#include<bits/stdc++.h>
using namespace std;

struct Log{
    string userId;
    int64_t amount;
    int64_t time;
    Log(){
        userId="";
        amount=0LL;
        time=0LL;
    }
};

class Logger{
   
    vector<Log> Logs;
    map<string,int64_t> UserSpendings;

    Log stringtoLog(string& s){
        Log log;
        string current="";
        int size=s.size();
        int counter=0;
        for(int i=1;i<size;i++){
            if(s[i]==','){
                if(counter==0){
                    log.userId=current;
                    counter++;
                    current="";
                }else{
                    log.amount=stoi(current);
                    current="";
                    counter++;
                }
                continue;
            }
            current+=s[i];
        }
        log.time=stoi(current);
        return log;
    }

    public:
    
    void read(){
        string logLine;
        while(getline(cin,logLine)){
            Log log=stringtoLog(logLine);
            Logs.push_back(log);
            UserSpendings[log.userId]+=log.amount;
        }
    }

    void printLogs(){
        for(auto log: Logs){
           cout<<log.userId<<" "<<log.amount<<" "<<log.time<<"\n";
        }
    }

    void printUsersSpending(){
        for(auto user: UserSpendings){
            cout<<user.first<<" "<<user.second<<"\n";
        }
    }
};


int main(){

    Logger LogHandler;
    LogHandler.read();
    LogHandler.printLogs();
    LogHandler.printUsersSpending();
   
 return 0;
}