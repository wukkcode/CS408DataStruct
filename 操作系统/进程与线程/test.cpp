#include <stdio.h>

while (true)
{
    进入区; // 检查和上锁
    临界区; // 访问
    退出区; // 退出和解锁
    剩余区; // 剩余的任务
}

// 布尔型共享变量 lock 表示当前临界区是否被加锁
// true 表示已经加锁，false 表示未加锁
bool TestAndSet(bool *lock)
{
    bool old;
    old = *lock; // old 变量用来存储原来 lock 的值
    *lock = true; // 无论之前是否已经加锁，都将 lock 设为 true
    return old; // 返回 lock 原来的值
}

// 以下是使用 TSL 指令实现互斥的算法逻辑
while (TestAndSet (&lock)); // 进入区“上锁”并“检查”
临界区代码段...
lock = false; // 退出区“解锁”
剩余区代码段...

//Swap 指令的作用是交换两个变量的值
Swap (bool *a, bool *b)
{
    bool temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 以下是用 Swap 指令实现互斥的算法逻辑
// lock 表示当前临界区是否被加锁
bool old = true;
while (old == true)
    Swap(&lock, &old);
临界区代码段...
lock = false;
剩余区代码段...

acquire()
{
    while (!available)
    {
        // 忙等待
    }
    available = false; // 获得锁
}

release()
{
    available = true; // 释放锁
}


int S = 1; // 初始化整型信号量S，表示当前系统中可用的临界资源数

// wait原语，相当于“进入区”
void wait(int S)
{
    while (S <= 0); //如果没有可用的资源，则一直循环等待
    S = S - 1;
}

// signal原语，相当于“退出区”
void signal(int S)
{
    S = S+1; // 使用完资源后，在退出区释放资源
}

// 记录型信号量的结构定义
typedef struct
{
   int value; // 剩余资源数
   struc process *L; // 等待队列
} semaphore;

// 某进程需要使用某种资源时，通过wait原语进行申请
void wait(semaphore S)
{
    S.value--;
    if (S.value < 0)
    {
        block(S.L); // 没有资源可用则阻塞该进程
    }
}

// 进程使用完资源后，通过signal原语释放
void signal(semaphore S)
{
    S.value++;
    if (S.value <= 0)
    {
        wakeup(S.L); // 当前进程释放资源后，唤醒等待的进程（如果有）
    }
}



// 信号量机制实现互斥
semaphore mutex = 1; // 初始化互斥信号量

P0()
{
    ...
    P(mutex); // 进入区，申请并上锁资源
    使用临界资源... //临界区，访问资源
    V(mutex); // 退出区，释放资源
    ...
}

P1()
{
    ...
    P(mutex); // 进入区，申请并上锁资源
    使用临界资源... //临界区，访问资源
    V(mutex); // 退出区，释放资源
    ...
}




// 信号量机制实现同步
semaphore S = 0; // 初始化同步信号量，初始值为0

P0()
{
    代码1;
    代码2;
    V(S);
    代码3;
}

P1()
{
    P(S);
    代码4;
    代码5;
    代码6;
}


semaphore mutex = 1; // 互斥信号量，表示对缓冲区的互斥访问
semaphore full = 0; // 同步信号量，表示产品的数量，也即对非空缓冲区的数量
semaphore empty = n; // 同步信号量，表示空闲缓冲区的数量

producer()
{
    while (true)
    {
        生产一个产品;
        P(mutex); ① // 互斥访问缓冲区
        P(empty); ② // 消耗一个空闲缓冲区
        把产品放入缓冲区;
        V(mutex); // 释放缓冲区
        V(full); // 增加一个产品
    }
}

consumer()
{
    while (true)
    {
        P(mutex); ③ // 互斥访问缓冲区
        P(full); ④ // 消耗一个产品
        从缓冲区取走一个产品;
        V(mutex); // 互斥访问缓冲区
        V(empty); // 增加一个空闲缓冲区
        使用产品;
    }
}


semaphore mutex = 1; // 互斥信号量，互斥访问盘子（可去掉）
semaphore plate = 1; // 同步信号量，盘子的状态
semaphore apple = 0; // 同步信号量，苹果的数量
semaphore orange = 0; // 同步信号量，橘子的数量

father()
{
    while (true)
    {
        准备一个苹果;
        P(plate);
        把苹果放入盘子;
        V(apple);
    }
}

mother()
{
    while (true)
    {
        准备一个橘子;
        P(plate);
        把橘子放入盘子;
        V(orange);
    }
}

daughter()
{
    while (true)
    {
        P(apple);
        从盘子中取出苹果;
        V(plate);
        吃掉苹果;
    }
}

son()
{
    while (true)
    {
        P(orange);
        从盘子中取出橘子;
        V(plate);
        吃掉橘子;
    }
}

semaphore offer1 = 0; // 桌子上组合一的数量
semaphore offer2 = 0; // 桌子上组合二的数量
semaphore offer3 = 0; // 桌子上组合三的数量
semaphore finish = 0; // 抽烟是否完成
int flag = 0; // 用于实现三个抽烟者轮流抽烟



provider()
{
    while (true)
    {
        if (flag == 0)
        {
            将组合材料1放到桌子上;
            V(offer1);
        }
        else if (flag == 1)
        {
            将组合材料2放到桌子上;
            V(offer2);
        }
        else
        {
            将组合材料3放到桌子上;
            V(offer3);
        }
        flag = (flag + 1) % 3;
        P(finish); // 放完材料之后阻塞，等待被唤醒
    }
}

smoker1()
{
    while (true)
    {
        P(offer1);
        从桌子上拿走所需组合材料;
        卷烟，抽烟;
        V(finish);
    }
}

smoker2()
{
    while (true)
    {
        P(offer2);
        从桌子上拿走所需组合材料;
        卷烟，抽烟;
        V(finish);
    }
}

smoker3()
{
    while (true)
    {
        P(offer3);
        从桌子上拿走所需组合材料;
        卷烟，抽烟;
        V(finish);
    }
}

provider()
{
    while(true)
    {
        /*
            some code section...
        */

        flag = random();
    }
}


// 读者写者问题


// 版本1
semaphore rw = 1; // 用于实现对共享文件的访问

writer()
{
    while (true)
    {
        P(rw); // 写之前加锁
        写文件;
        V(rw); // 写完成解锁
    }
}

reader()
{
    while (true)
    {
        P(rw); // 读之前加锁
        读文件;
        V(rw); // 读完成解锁
    }
}

版本2
semaphore rw = 1; // 用于实现对共享文件的访问
int count = 0; // 用于记录当前有几个读进程访问共享文件

writer()
{
    while (true)
    {
        P(rw); // 写之前加锁
        写文件;
        V(rw); // 写完成解锁
    }
}

reader()
{
    while (true)
    {
        if (count == 0)
        {
            P(rw); // 第一个读进程读之前加锁
        }
        count++;
        读文件;
        count--;
        if (count == 0)
        {
            V(rw); // 最后一个读进程读完成解锁
        }
    }
}


版本3


semaphore rw = 1; // 用于实现对共享文件的访问
semaphore mutex = 1; // 用于实现对count变量的互斥访问
int count = 0; // 用于记录当前有几个读进程访问共享文件

writer()
{
    while (true)
    {
        P(rw); // 写之前加锁
        写文件;
        V(rw); // 写完成解锁
    }
}

reader()
{
    while (true)
    {
        P(mutex);
        if (count == 0)
        {
            P(rw); // 第一个读进程读之前加锁
        }
        count++;
        V(mutex);
        读文件;
        P(mutex);
        count--;
        if (count == 0)
        {
            V(rw); // 最后一个读进程读完成解锁
        }
        V(mutex);
    }
}

// 版本4

semaphore rw = 1; // 用于实现对共享文件的访问
semaphore mutex = 1; // 用于实现对count变量的互斥访问
semaphore w = 1; // 用于实现“写优先”（读写公平）
int count = 0; // 用于记录当前有几个读进程访问共享文件

writer()
{
    while (true)
    {
        P(w);
        P(rw); // 写之前加锁
        写文件;
        V(rw); // 写完成解锁
        P(w);
    }
}



reader()
{
    while (true)
    {
        P(w);
        P(mutex);
        if (count == 0)
        {
            P(rw); // 第一个读进程读之前加锁
        }
        count++;
        V(mutex);
        V(w);
        读文件;
        P(mutex);
        count--;
        if (count == 0)
        {
            V(rw); // 最后一个读进程读完成解锁
        }
        V(mutex);
    }
}

// 哲学家进餐问题
// 方案1
semaphore chopsticks[5] = {1, 1, 1, 1, 1}; // 为五根筷子分别设置互斥信号量
semaphore philosopher = 4; // 设置同时进餐的哲学家数量

pi()
{
    while(true)
    {
        P(philosopher);
        P(chopsticks[i]);
        P(chopsticks[(i+1)%5]);
        吃饭;
        V(chopsticks[i]);
        V(chopsticks[(i+1)%5]);
        V(philosopher);
        思考;
    }
}

// 方案2
semaphore chopsticks[5] = {1, 1, 1, 1, 1}; // 为五根筷子分别设置互斥信号量

pi()
{
    while(true)
    {
        if(i % 2 == 1)
        {
            P(chopsticks[i]);
            P(chopsticks[(i+1)%5]);
        }
        else
        {
            P(chopsticks[(i+1)%5]);
            P(chopsticks[i]);
        }
        吃饭;
        V(chopsticks[i]);
        V(chopsticks[(i+1)%5]);
        思考;
    }
}

// 方案3


semaphore chopsticks[5] = {1, 1, 1, 1, 1}; // 为五根筷子分别设置互斥信号量
semaphore mutex = 1; // 哲学家互斥拿筷子

pi()
{
    while(true)
    {
        P(mutex);
        P(chopsticks[i]);
        P(chopsticks[(i+1)%5]);
        V(mutex);
        吃饭;
        V(chopsticks[i]);
        V(chopsticks[(i+1)%5]);
        思考;
    }
}

static class moniter
{
    private Item buffer[] = new Item[N];
    private int count = 0;
    public synchronized void insert (Item item)
    {
        ......
    }
}



static class Producer Consumer
{
    condition full, empty; // 条件变量
    int count = 0; // 缓冲区的产品数
    void insert() // 把产品放入缓冲区
    {
        if (count == N)
        {
            wait(full);
        }
        count++;
        insert_item(item);
        if (count == 1) // 有产品就尝试去唤醒消费者进程
        {
            signal(empty);
        }
    }
    Item remove() // 从缓冲区中取出一个产品
    {
        if (count == 0)
        {
            wait(empty);
        }
        count--;
        if (count == N-1)
        {
            signal(full); // 有空位了就尝试去唤醒生产者进程
        }
        return remove_item();
    }
}


// 生产者进程
producer()
{
    while(true)
    {
        item = 生产一个产品;
        ProducerConsumer.insert(item);
    }
}


// 消费者进程
consumer()
{
    while(true)
    {
        item = ProducerConsumer.remove();
        消费产品item;
    }
}


// 面包店问题（座位无上限，不能休息）


int waiting = 0; // 等待的顾客
semaphore mutex = 1; // 互斥取号和叫号
semaphore service = 0; // 服务同步

// 顾客进程
customer_i()
{
    P(mutex);
    取号;
    waiting++;
    V(mutex);
    P(serveice);
    等待被叫号;
    买面包离开;
}



// 面包销售人员进程
seller_j()
{
    while(true)
    {
        P(mutex);
        if (waiting > 0) // 有顾客等号
        {
            叫号;
            waiting--;
            V(mutex);
            V(serveice);
            提供服务;
        }
        else // 没有顾客
        {
            V(mutex);
        }
    }
}


// 银行服务问题（座位有限制，营业员不能休息）


int waiting = 0; // 等待服务的顾客人数
semaphore service = 0; // 服务同步
semaphore mutex = 1; // 互斥取号和叫号

// 顾客进程
customer_i()
{
    P(mutex);
    if (waiting >= 10)
    {
        V(mutex);
        return; 
    }
    取号;
    waiting++;
    V(mutex);
    P(service);
    等待被服务;
    服务完成离开;
}



// 营业员进程
assistant_j()
{
    while(true)
    {
        P(mutex);
        if (waiting > 0)
        {
            叫号;
            waiting--;
            V(mutex);
            V(service);
            提供服务;
        }
        else
        {
            V(mutex);
        }
    }
}


// 理发师问题（座位有限制，理发师可以休息）


int waiting = 0; // 等待理发的人
semaphore service = 0; // 理发同步
semaphore customer = 0; // 无人了让理发师进行休息
semaphore mutex = 1; // 互斥取号和叫号

// 顾客进程
customer_i()
{
    P(mutex);
    if (waiting >= 10)
    {
        V(mutex);
        return;
    }
    取号;
    waiting++;
    V(mutex);
    V(customer);
    P(service);
    等待被理发;
    理发完成离开;
}



// 理发师进程
barber()
{
    while (true)
    {
        P(mutex);
        if(waiting > 0)
        {
            叫号;
            waiting--;
            V(mutex);
            V(service);
            提供服务;
        }
        else
        {
            V(mutex);
            P(customer);
        }
    }  
}


semaphore S2 = S3 = 0;
semaphore Sb = Sy = Sz = 0;

P1()
{
    从输入设备输入数据a;
    V(S2);
    P(Sb);
    x = a + b;
    P(Sy);
    P(Sz);
    使用打印机x、y、z;
}

P2()
{
    P(S2)
    从输入设备输入数据b;
    V(Sb);
    V(S3);
    y = a * b;
    V(Sy);
    V(Sy);
}

P3()
{   
    P(S3);
    从输入设备输入数据c;
    P(Sy);
    z = y + c - a;
    V(Sz);
}

// 过桥问题
int count_STON = 0;
int count_NTOS = 0;
semaphore bridge = 1; // 不同方向的车互斥过桥
semaphore mutex1 = 1;
semaphore mutex2 = 1;

PSTON()
{
    P(mutex1);
    if (count_STON == 0)
    {
        P(bridge);
    }
    count_STON++;
    V(mutex1);
    过桥;
    P(mutex1);
    count_STON--;
    if (count_STON == 0)
    {
        V(bridge);
    }
    V(mutex1);
}

PNTOS()
{
    P(mutex2);
    if (count_NTOS == 0)
    {
        P(bridge);
    }
    count_NTOS++;
    V(mutex2);
    过桥;
    P(mutex2);
    count_NTOS--;
    if (count_NTOS == 0)
    {
        V(bridge);
    }
    V(mutex2);
}


// 工人组装问题
semaphore empty = N;
semaphore mutex = 1;
semaphore wheel = 0; // 车轮的数量
semaphore frame = 0; // 车架的数量
semaphore max_wheel = N - 1;
semaphore max_frame = N - 2;

worker1()
{
    do
    {
        加工一个车架;
        P(max_frame);
        P(empty);
        P(mutex);
        车架放入箱中;
        V(mutex);
        V(frame);

    }while(true)
}

worker2()
{
    do
    {
        加工一个车轮;
        P(max_wheel);
        P(empty);
        P(mutex);
        车轮放入箱中;
        V(mutex);
        V(wheel);
    } 
    while (true);
    
}

worker3()
{
    do
    {
        P(frame);
        P(mutex);
        箱子中取一个车架;
        V(mutex);
        V(empty);
        V(max_frame);
        P(wheel);
        P(wheel);
        箱子中取两个车轮;
        V(empty);
        V(empty);
        V(max_wheel);
        V(max_wheel);
        组装为一台车;
    }
    while(true)
}

// 生产者消费者问题（混入两面派）
semaphore empty = 1;
semaphore full = 0;
semaphore mutex = 1;

progress_P()
{
    while(true)
    {
        生产产品;
        P(empty);
        P(mutex);
        产品放入缓冲区;
        V(mutex);
        V(full);
    }
}

progress_Q()
{
    while(true)
    {
        P(full);
        P(mutex);
        从缓冲区中拿走产品;
        V(mutex);
        V(empty);
    }
}

progress_R()
{
    while(true)
    {
        if (full == 1)
        {
            P(full);
            P(mutex);
            从缓冲区中拿走产品;
            V(mutex);
            V(empty);
        }
        if (empty == 1)
        {
            生产产品;
            P(empty);
            P(mutex);
            产品放入缓冲区;
            V(mutex);
            V(full);
        }
    }
}

// 放小电影问题
int count1 = 0;
semaphore mutex1 = 1;
semaphore theater = 1;

viewer()
{
    while (true)
    {
        P(mutex1);
        if (count1 == 0)
        {
            P(theater);
        }
        count1++;
        V(mutex1);
        看小电影;
        P(mutex1);
        count1--;
        if (count1 == 0)
        {
            V(theater);
        }
        V(mutex1);
    }
}

// 南开大学与天津大学相互交流问题
semaphore T2N = 1;
semaphore N2T = 1;
semaphore K_section = 1;
semaphore L_section = 1;

process_T2N
{
    while(true)
    {
        P(T2N);
        P(L_section);
        从天津大学出发;
        V(L_section);
        进入安全岛;
        P(K_section);
        出安全岛;
        到达南开大学;
        V(K_section);
        V(T2N);
    }
}

process_N2T
{
    while(true)
    {
        P(N2T);
        P(K_section);
        从南开大学出发;
        V(K_section);
        进入安全岛;
        P(L_section);
        出安全岛;
        到达天津大学;
        V(L_section);
        V(N2T);
    }
}

// 公共汽车驾驶员和售票员的爱恨情仇
semaphore S1 = 0; // 驾驶员启动车辆和售票员关车门的同步关系（先关车门再启动）
semaphore S2 = 0; // 驾驶员到站和售票员开车门的同步关系（先到站再开门）


process_driver()
{
    while(true)
    {
        P(S1);
        启动车辆;
        正常行车;
        到站停车;
        V(S2);
    }
}

process_seller()
{
    while (true)
    {
        关车门;
        V(S1);
        售票;
        P(S2);
        开车门;
    }
}


// 闲得无聊取数问题
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;


int count_odd = 0;
int count_even = 0;

process_P1()
{
    while(true)
    {
        produce();
        P(empty);
        P(mutex);
        put();
        V(mutex);
        V(full);
    }
}

process_P2()
{
    while(true)
    {
        if (countodd() > 0)
        {
            P(full);
            P(mutex);
            getodd();
            V(mutex);
            V(empty);
            countodd();
        }
    }
}

// 另一种做法
semaphore mutex = 1;
semaphore empty = N;
semaphore odd_count = 0;
semaphore even_count = 0;

process_P1()
{
    while(true)
    {
        int temp = produce();
        P(empty);
        P(mutex);
        put(temp);
        V(mutex);
        if (temp % 2 == 0)
        {
            V(even_count);

        }
        else
        {
            V(odd_count);
        }
    }
}

process_P2()
{
    while (true)
    {
        P(odd_count);
        P(mutex);
        get_odd();
        V(mutex);
        V(empty);
        countodd();
    }
}

process_P3()
{
    while (true)
    {
        P(even_count);
        P(mutex);
        get_even();
        V(mutex);
        V(empty);
        couneven();
    }
}

// 博物馆参观问题
semaphore mutex_door = 1; // 出入口互斥
semaphore empty = 500;

process_visitor()
{
    while(true)
    {
        P(empty);
        P(mutex_door);
        进门;
        V(mutex_door);
        参观;
        P(mutex_door);
        出门;
        V(mutex_door);
        V(empty);
    }
}

// 老旧的生产者消费者问题（消费者比较贪心）
semaphore mutex = 1; // 互斥访问缓冲区
semaphore empty = 1000; // 缓冲区的剩余空间
semaphore full = 0; // 缓冲区的产品
semaphore status = 1; // 确保一个消费者拿完10个产品

producer()
{
    while(true)
    {
        生产产品;
        P(empty);
        P(mutex);
        产品放入缓冲区;
        V(mutex);
        V(full);
    }
}


consumer()
{
    while (true)
    {
        P(status);
        for (int count = 0; count < 10; count++)
        {
            P(full);
            P(mutex);
            取产品;
            V(mutex);
            V(empty);
            消费产品;
        }
        V(status);
    }
}


// 一种很新的辩论问题
semaphore empty_A = M-x;
semaphore empty_B = N-y;
semaphore count_A = x;
semaphore count_B = y;
semaphore mutex_A = 1; // 保证信箱A的互斥
semaphore mutex_B = 1; // 保证信箱B的互斥

process_A()
{
    while(true)
    {
        P(count_A);
        P(mutex_A);
        从A的信箱中取出一个邮件;
        V(mutex_A);
        V(empty_A);
        回答问题并提出一个新问题;
        P(empty_B);
        P(mutex_B); 
        将邮件放入B的信箱; 
        V(mutex_B);
        V(count_B);
    }
}

process_B()
{
    while(true)
    {
       P(count_B);
       P(mutex_B);
       从B的信箱中取出一个邮件;
       V(mutex_B);
       V(empty_B);
       回答问题并提出一个新问题;
       P(empty_A);
       P(mutex_A);
       将邮件放入A的信箱; 
       V(mutex_A);
       V(count_A);
    }
}

// 三线程合作问题(仅仅是互斥关系，对三个进程的推进顺序并没有严格的要求)
// 需要注意的是thread1和thread2的只是对变量y进行读操作所以可以对y同时访问
semaphore mutex_y1;
semaphore mutex_y2;
semaphore mutex_z;

thread1()
{
    cnum w;
    P(mutex_y1);
    w = add(x, y);
    V(mutex_y1);
    ...
}

thread2
{
    cnum w;
    P(mutex_y2);
    P(mutex_z);
    w = add(y, z);
    V(mutex_z);
    V(mutex_y2);
    ...
}

thread3
{
    cnum w;
    w.a = 1;
    w.b = 1;
    P(mutex_z);
    z = add(z, w);
    V(mutex_z);
    P(mutex_y1);
    P(mutex_y2);
    y = add(y, w);
    V(mutex_y1);
    V(mutex_y2);
}


// 有碗的哲学家进餐问题（容易死锁）
semaphore bowl = m;
semaphore philosopher = min(m, n-1); // 限制同时进餐的哲学家的数量
semaphore chopsticks[n];
for (int i = 0; i < n; i++)
{
    chopsticks[i] = 1;
}

process_philosopher_i()
{
    while(true)
    {
        P(bowl);
        拿碗;
        P(chopsticks[i]); // 拿左手边的筷子
        P(chopsticks[(i+1) % n]); // 拿右手边的筷子
        拿筷子;
        进餐;
        V(chopsticks[i]); // 放下左手边的筷子
        V(chopsticks[(i+1) % n]); // 放下右手边的筷子
        V(bowl);
        思考;
    }
}


// 简单的前驱后继关系
semaphore syn_AC = 0;
semaphore syn_BC = 0;
semaphore syn_CE = 0;
semaphore syn_DE = 0;

process_A()
{
    finish_A();
    V(syn_AC);
    ...
}

process_B()
{
    finish_B();
    V(syn_BC);
    ...
}

process_C()
{
    P(syn_AC);
    P(syn_BC);
    finish_C();
    V(syn_CE);
    ...
}

process_D()
{
    finish_D();
    V(syn_DE);
    ...
}

process_E()
{
    P(syn_CE);
    P(syn_DE);
    finish_E();
}

// 又是简单的前驱后继
semaphore syn_AC = 0;
semaphore syn_CE = 0;

thread_T1()
{
    do_A();
    V(syn_AC);
    P(syn_CE);
    do_E();
    do_F();
}

thread_T2()
{
    do_B();
    P(syn_AC);
    do_C();
    V(syn_CE);
    do_D();
}


// 教练和队员共浴问题（读者写者问题）
// 教练和队员是互斥访问澡堂的

方法1: 队员优先
int count = 0; // 同时洗澡的队员人数
semaphore bath = 1;
semaphore mutex = 1;

// 教练
process_coach()
{
    while(true)
    {
        进入澡堂;
        P(bath);
        教练洗澡;
        V(bath);
        开心的离开了;
    }
}

// 队员
process_player()
{
    while(true)
    {
        进入澡堂;
        P(mutex);
        if (count == 0)
        {
            P(bath);
        }
        count++;
        V(mutex);
        正在洗澡;
        P(mutex);
        count--;
        if (count == 0)
        {
            V(bath);
        }
        V(mutex);
        开心的离开了;
    }
}

方法1: 队员教练优先
int count = 0; // 同时洗澡的队员人数
semaphore bath = 1;
semaphore mutex = 1;
semaphore equity = 1;

// 教练队员公平洗澡
process_coach()
{
    while(true)
    {
        P(equlity);
        P(bath);
        教练洗澡;
        V(bath);
        V(qulity);
        开心的离开了;
    }
}

// 队员
process_player()
{
    while(true)
    {
        P(equlity);
        P(mutex);
        if (count == 0)
        {
            P(bath);
        }
        count++;
        V(mutex);
        V(equlity);
        正在洗澡;
        P(mutex);
        count--;
        if (count == 0)
        {
            V(bath);
        }
        V(mutex);
        开心的离开了;
    }
}

// 方法3（写优先）

semaphore readLock = 1;
semaphore writelock = 1;
semaphore rmutex = 1; // 计数器互斥访问
semaphore wmutex = 1; // 计数器互斥访问
int readCount = 0;
int writeCount = 0;

// 读者进程


process_reader()
{
    while(true)
    {
        P(readLock);
        P(rmutex);
        readCount++;
        if (readCount == 1)
        {
            P(writeLock);
        }
        V(rmutex);
        V(readLock);
        读文件;
        P(rmutex);
        readCount--;
        if (readCount == 0)
        {
            V(writeLock);
        }
        V(rmutex);
    }
}

// 写者进程


process_writer()
{
    while(true)
    {
        P(wmutex);
        writeCount++;
        if (writeCount == 1)
        {
            P(readLock);
        }
        V(wmutex);
        P(writeLock); // 写进程互斥
        写文件;
        V(writeLock);
        P(wmutex);
        writeCount--;
        if (writeCount == 0)
        {
            V(readLock);
        }
        V(wmutex);
    }
}

// 干饭人干饭问题
semaphore plate = N;
semaphore seat = M;
semaphore mutex = 1; // 让干饭人一下拿4个盆，以免发生死锁不能吃饭

process_eaters()
{
    while(true)
    {
        P(mutex);
        for (int i = 0; i < 4; i++)
        {
            P(plate);
        }
        V(mutex);
        打荤菜;
        打素菜;
        打汤;
        打米饭;
        P(seat);
        坐下干饭;
        V(seat);
        干饭完成;
        for (int i = 0; i < 4; i++)
        {
            V(plate);
        }
    }
}

int global_var_x = 1;

int main()
{
    f1();
}

int static_array[N];
int global_array[N];

int function1()
{
    return  1;
}



f2()
{

}