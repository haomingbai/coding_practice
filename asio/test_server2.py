import asyncio
import random
import string
import time

async def test_echo_client(client_id, data_size):
    # 创建TCP连接
    reader, writer = await asyncio.open_connection('127.0.0.1', 10086)
    
    # 生成随机测试数据
    data = ''.join(random.choices(string.ascii_letters + string.digits, k=data_size)).encode()
    start_time = time.perf_counter()
    
    # 发送数据
    writer.write(data)
    await writer.drain()
    
    # 接收回显数据
    echoed = await reader.read(len(data))
    latency = time.perf_counter() - start_time
    
    # 验证结果
    if echoed == data:
        print(f"Client {client_id}: Success! Latency: {latency*1000:.2f}ms Size: {len(data)} bytes")
    else:
        print(f"Client {client_id}: FAILED! Expected {len(data)} bytes, got {len(echoed)} bytes")
    
    writer.close()
    await writer.wait_closed()

async def main():
    # 配置测试参数
    clients = 50          # 并发客户端数量
    data_size = 1024      # 每个客户端发送的数据大小
    
    # 创建并发任务
    tasks = [
        test_echo_client(i, data_size) 
        for i in range(clients)
    ]
    
    # 执行并发测试
    start = time.perf_counter()
    await asyncio.gather(*tasks)
    total_time = time.perf_counter() - start
    
    # 打印测试摘要
    print(f"\nTest completed: {clients} clients")
    print(f"Total time: {total_time:.3f} seconds")
    print(f"Throughput: {clients/total_time:.1f} req/sec")
    print(f"Total data: {(clients * data_size * 2) / (1024*1024):.2f} MB")

if __name__ == "__main__":
    asyncio.run(main())
