#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 声明类
class Publisher;
class Subscriber;

// 订阅者接口 ？内含纯虚函数？
class Subscriber
{
public:
    virtual void update(const string& topic,const string& message) = 0;
};

class Publisher
{
public:
    
    void subscribe(const string& topic, Subscriber *subscriber)
    {
        subscribers_[topic].push_back(subscriber);

    }

    void unsubscribe(const string& topic, Subscriber *subscriber)
    {
        auto iter = subscribers_.find(topic);
        if(iter != subscribers_.end())
        {
            auto& subcribers = iter->second;  // 注意必须引用才能修改原值
            for(auto iter2 = subcribers.begin(); iter2 != subcribers.end(); ++iter2)
            {
                if(*iter2 == subscriber)
                {
                    subcribers.erase(iter2);
                    break;
                }
            }
        }
    }

    void notify(const string& topic, const string& message)
    {
        // for(auto subscriber : subscriber_)
        // {
        //     subscriber->update(message);
        // }
        auto iter = subscribers_.find(topic);
        if(iter != subscribers_.end())
        {
            auto& subscribers = iter->second;
           for (auto subscriber : subscribers) {
                subscriber->update(topic, message);
            }
        }
    }


private:
    unordered_map<string, vector<Subscriber*>> subscribers_;
};

// 订阅者1
class Subscriber1 : public Subscriber
{
public:
    virtual void update(const string& topic, const string& message)
    {
        cout << "Subcribe1 received message:" << message << "on topic :" << topic << endl;
    }
};

class Subscriber2 : public Subscriber
{
public:
    virtual void update(const string& topic, const string& message)
    {
        cout << "Subcribe2 received message:" << message << "on topic :" << topic << endl;
    }
};

int main()
{
    Publisher publisher;
    Subscriber1 subscriber1;
    Subscriber2 subscriber2;


    //添加订阅者
    publisher.subscribe("topic1", &subscriber1);
    publisher.subscribe("topic2", &subscriber2);

    publisher.notify("topic1", "Hello, world!");   

    // 删除订阅者
    publisher.unsubscribe("topic1", &subscriber1);

    // 发送另一条消息
    publisher.notify("topic1", "Goodbye!");
    publisher.notify("topic2", "Hello, again!");

    return 0;
}