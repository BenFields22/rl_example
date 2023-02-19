#include "Utils.hpp"

Logger* u_log = new Logger("UTIL",1,Color::BLUE);

#ifdef _WIN32
Logger::Logger(std::string id, int logFlag, int color) {
    loggerId = id;
    loggerFlag = logFlag;
    loggerColor = color;
}

void Logger::print(std::string text) {
    if (loggerFlag == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), loggerColor);
        std::cout << "[" << loggerId << "]";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        std::cout << ": " << text << std::endl;
    }
}
#else
Logger::Logger(std::string id, int logFlag, int color) {
    loggerId = id;
    loggerFlag = logFlag;
    loggerColor = "\033[0;" + std::to_string(color) + "m";
}

void Logger::print(std::string text) {
    if (loggerFlag == 1) {
        std::cout << loggerColor << loggerId << "\033[0;37m" << ": " << text << std::endl;
    }
}

#endif


Logger::~Logger() {
    print("Shutting Down Logger");
}

void log(Logger* log,std::string s){
    log->print(s);
}

std::vector<int> parseIntVec(){
    std::vector<int> v;
    std::string input;
    std::cin>>input;
    int start = 0;
    std::string del = ",";
    int end = input.find(del);
    if(end==-1){
        std::string ss = input.substr(1,input.length()-2);
        std::vector<int> v;
        v.push_back(int(stoi(ss)));
        printVecNum(v);
        return v;
    }
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            std::string ss = input.substr(start, end - start);
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-1));
            v.push_back(int(stoi(ss)));
        }
        else{
            std::vector<std::string> vi;
            std::string ss = input.substr(start, end - start);
            v.push_back(int(stoi(ss)));
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    std::string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-1, ss2.end());
    v.push_back(int(stoi(ss2)));
    printVecNum(v);
    return v;
}

std::vector<int> convertToIntVec(std::string input){
    std::vector<int> v;
    int start = 0;
    std::string del = ",";
    int end = input.find(del);
    if(end==-1){
        std::string ss = input.substr(1,input.length()-2);
        std::vector<int> v;
        v.push_back(int(stoi(ss)));
        //printVecNum(v);
        return v;
    }
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            std::string ss = input.substr(start, end - start);
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-1));
            v.push_back(int(stoi(ss)));
        }
        else{
            std::vector<std::string> vi;
            std::string ss = input.substr(start, end - start);
            v.push_back(int(stoi(ss)));
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    std::string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-1, ss2.end());
    v.push_back(int(stoi(ss2)));
    //printVecNum(v);
    return v;
}

std::vector<std::vector<int>> parse2DVecInt(){
    std::vector<std::vector<int>> v;
    std::string input;
    std::cin>>input;
    //log(u_log,input);
    int start = 0;
    std::string del = "],[";
    int end = input.find(del);
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            std::string ss = input.substr(start+1, end - start);
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-1)-1);
            //log(u_log,ss);
            v.push_back(convertToIntVec(ss));
        }
        else{
            std::vector<std::string> vi;
            std::string ss = input.substr(start-1, end - start+2);
            //log(u_log,ss);
            v.push_back(convertToIntVec(ss));
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    std::string ss2 ="[";
    ss2 += input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-1, ss2.end());
    //log(u_log,ss2);
    v.push_back(convertToIntVec(ss2));
    std::string l="";
    l+="[";
    for (int i = 0; i < v.size(); ++i) {
        if (i!=0) {
            l+=",";
        }
        l+="[";
       for(int k=0;k<v[i].size();k++){
            if (k!=0) {
                l+=",";
            }
            l+=std::to_string(v[i][k]);
       } 
        l+="]";
    }
    l+="]";
    log(u_log,l);
    return v;
}

std::vector<std::string> parseStringVec(){
    std::vector<std::string> v={};
    std::string input;
    std::cin>>input;
    int start = 0;
    std::string del = "\",\"";
    int end = input.find(del);
    int first = 0;
    while (end != -1) {
        if (first==0) {
            first=1;
            std::string ss = input.substr(start, end - start);
            int len = ss.length();
            ss.erase(ss.begin() + 0, ss.end()-(len-2));
            v.push_back(ss);
        }
        else{
            std::string ss = input.substr(start, end - start);
            v.push_back(ss);
        }
        start = end + del.size();
        end = input.find(del, start);
    }
    std::string ss2 = input.substr(start, end - start);
    int len2 = ss2.length();
    ss2.erase(ss2.begin() + len2-2, ss2.end());
    v.push_back(ss2);
    printVecString(v);
    return v;
}

ListNode* newNode(int key, ListNode* next)
{
    // allocate a new node in a heap and set its data
    ListNode* node = new ListNode();
    node->val = key;

    // set the `.next` pointer of the new node to point to the current
    // // first node of the list.
    node->next = next;

    return node;
}

ListNode* constructList(std::vector<int> const &keys)
{
    ListNode* head, *node = nullptr;

    // start from the end of the array
    for (int i = keys.size() - 1; i >= 0; i--)
    {
        node = newNode(keys[i], node);
        head = node;
    }

    return head;
}

void printVecString(std::vector<std::string>& v){
    std::string tmp="";
    tmp+="[";
    for (int i = 0; i < v.size(); ++i) {
        if (i!=0) {
            tmp+=",";
        }
        tmp+=v[i];
    }
    tmp+="]";
    log(u_log,tmp);
}
template<typename T>
void printVecNum(std::vector<T>& v){
    std::string tmp="";
    tmp+="[";
    for (int i = 0; i < v.size(); ++i) {
        if (i!=0) {
            tmp+=",";
        }
        tmp+=std::to_string(v[i]);
    }
    tmp+="]";
    log(u_log,tmp);
}
