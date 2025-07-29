#!/usr/bin/env python3
"""
测试 Boost.Asio 回显服务器的并发性能。
用法示例：
    ./test_echo.py --host 127.0.0.1 --port 12345 --clients 50 --messages 100
"""
import argparse
import asyncio
import time

async def echo_client(id: int, msg: str, host: str, port: int) -> float:
    """单个客户端发送一条消息并接收回显，返回往返时延。"""
    start = time.time()
    reader, writer = await asyncio.open_connection(host, port)
    writer.write(msg.encode())
    await writer.drain()
    await reader.read(len(msg) + 6)  # "Echo: " 前缀长度为6
    writer.close()
    await writer.wait_closed()
    return time.time() - start

async def run_test(host: str, port: int, clients: int, messages: int):
    """启动多个并发客户端，发送指定条数消息，统计性能指标。"""
    tasks = []
    for cid in range(clients):
        for mid in range(messages):
            msg = f"client{cid}-msg{mid}-{time.time()}"
            tasks.append(echo_client(cid, msg, host, port))

    start = time.time()
    latencies = await asyncio.gather(*tasks)
    total_time = time.time() - start

    total_msgs = len(latencies)
    total_latency = sum(latencies)
    print(f"并发客户端: {clients}")
    print(f"总消息数: {total_msgs}")
    print(f"总耗时: {total_time:.2f} 秒")
    print(f"吞吐量: {total_msgs/total_time:.2f} 消息/秒")
    print(f"平均单次往返时延: {total_latency/total_msgs:.4f} 秒")

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="测试 Boost.Asio 回显服务器并发性能")
    parser.add_argument('--host',   default='127.0.0.1', help='服务器地址')
    parser.add_argument('--port',   type=int, default=12345, help='服务器端口')
    parser.add_argument('--clients',type=int, default=10,    help='并发客户端数量')
    parser.add_argument('--messages',type=int, default=20,   help='每个客户端发送消息数量')
    args = parser.parse_args()
    asyncio.run(run_test(args.host, args.port, args.clients, args.messages))

