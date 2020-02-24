#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

struct connection {};
struct desconnection {};

connection connect (desconnection *pd)
{
        cout << "打开连接" << endl;
        return connection();
}

void disconnect (connection c)
{
        cout << "关闭连接" << endl;
}

//未使用share_ptr的版本
void f(desconnection &d)
{
        cout << "直接管理connect" << endl;
        connection c = connect(&d);
        //忘记调用disconnect关闭连接
        cout << endl;
}

void end_connection(connection *p) { disconnect(*p); }

//使用share_ptr的版本
void fl(desconnection &d)
{
        cout << "用shared_ptr管理connect" << endl;
        connection c = connect(&d);
        //指定删除器
       // shared_ptr<connection> p(&c, end_connection);
        //使用lambda
        shared_ptr<connection> p(&c,
                [](connection *p) {disconnect(*p); });
        
        //忘记调用disconnect关闭连接
        
        cout << endl;
}
int main(int argc, char const *argv[])
{
        desconnection d;
        f(d);
        fl(d);
        return 0;
}
