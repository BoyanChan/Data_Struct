/*计算一个式子表达式的思路:
 * 一,将中缀表达式转换成后缀表达式
    1）如果遇到操作数，我们就直接将其输出。
    2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
    3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
    4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。
    弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
    5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。
 * 二,后缀表达式求值
    规则：从左到右遍历表达式的每个数字和符号，遇到是数字就进栈，
    遇到是符号，就将处于栈顶两个数字出栈，进行运算，
    运算结果进栈，一直到最终获得结果。
 */

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

bool Number(char ch)//判断是否为数字，是则返回true
{
    return ch >= 48 && ch <= 57;
}

void InPut(char *&str)//接收输入的中缀表达式的函数，并简单判断是否合法
{
    cout << "Please Enter What You Want To calculation:" << endl;
    while (true) {
        cin >> str;


        if (Number(str[0]))//中缀表达式的第一个必定是数字，如果不是，则非法
        {
            break;
        } else {
            cout << "Illegal Input,Please Input Again:";
            delete[] str;
        }
    }
}

int GetPriority(char sy)//设置各个操作符的优先级
{
    switch (sy) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 3;
        case '*':
        case '/':
            return 5;
        case ')':
            return 6;
        default:
            return -1;
    }
}


void AddSpace(char *&arr)//给转成的后缀表达式的数字和符号添加空格，区分每个字符
{
    *arr = ' ';
    arr++;
}

char *GetBack()//获取后缀表达式的函数
{
    char *middle = new char[30];
    char *back = new char[30];
    char *backend = back;
    InPut(middle);
    stack<char> s;
    s.push('#');
    while (*middle) {
        if (Number(*middle) || *middle == '.')//如果是数字或者小数的话，直接输出
        {
            *back = *middle;
            back++, middle++;
        } else {
            if (Number(*(back - 1)))//只有他的上一个时数字的话，才继续给空格
                //否则遇到多个操作符，则输出域会存在多个空格
            {
                //*back = ' ';
                //back++;
                AddSpace(back);
            }
            if (*middle == ')')//如果右括号的话，输出所有操作符直到遇到左括号，并抛弃相对应的一堆括号
            {
                while (s.top() != '(') {
                    *back = s.top();
                    s.pop();
                    back++;
                    middle++;
                    AddSpace(back);
                }
                s.pop();//抛弃左括号
            } else if (*middle == '(')//遇到左括号，则进入栈
            {
                s.push(*middle);
                middle++;
            } else if (GetPriority(*middle) > GetPriority(s.top()))//如果栈内的操作符优先级高于栈外的优先级，则入栈
            {
                s.push(*middle);
                middle++;
            } else if (GetPriority(*middle) <= GetPriority(s.top()))
                //如果栈内的操作符优先级低于或等于栈外的优先级，输出栈内的符号，并入栈栈外的符号
            {
                *back = s.top();
                s.pop();
                s.push(*middle);
                back++;
                middle++;
                AddSpace(back);
            }
        }
    }
    while (s.top() != '#')//中缀表达式遍历完成，但是=栈中还有符号存在，一一出栈输出
    {
        AddSpace(back);
        *back = s.top();
        s.pop();
        back++;
    }
    *back = '\0';
    cout << "The Back Is: " << backend << endl;
    return backend;
}

double GetNumber(char *&arr) {
    //因为输出为char*，所以可能两位数以上的数字被拆开，此函数为正确得到数字
    double sum[10] = {0};
    int i = 0;
    double result = 0;
    while (*arr != ' ') {
        sum[i] = *arr - 48;
        i++;
        arr++;
    }
    int k = i - 1;
    for (int j = 0; j < i; j++, k--) {
        result += (sum[j] * pow(10, k));
    }
    return result;
}

double Cauculate(char ch, double left, double right)//各个操作符对应的操作
{
    switch (ch) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            return 0;
            break;
    }
}

double CountBack(char *back) {
    stack<double> s;
    while (*back) {
        if (Number(*back))//遇到数字
        {
            s.push(GetNumber(back));//将正确的数字入栈
        } else if (*back == ' ') {
            back++;//遇到空格跳过
        } else {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(Cauculate(*back, b, a));//遇到符号时，取栈顶的第二个数和第一个数求解，并入栈
            back++;
        }
    }
    while (s.size() >= 2)//最终栈内存在的数大于2时，继续计算，直到只剩下一个数
    {
        double a = s.top();
        s.pop();
        double b = s.top();
        s.pop();
        s.push(Cauculate(*back, b, a));
    }
    //返回这个数字，既是最终结果
    return s.top();
}

void FunTest() {
    cout << "The Result Is: " << CountBack(GetBack()) << endl;
}

int run() {
    FunTest();
    system("pause");
    return 0;
}
