#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Message{
public:
    string _sender;
    string _reciever;
    string _msg;
    Message(string sender, string reciever, string msg): _sender(sender), _reciever(reciever), _msg(msg){}
    void Display(){
        cout << _reciever << " recieved following msg from " << _sender << " :: " << endl << _msg << endl;
    }
};

class MessageLog{
    static  vector<Message *> msgLog;
public:
    static void logMsg(Message *msg){
        msgLog.push_back(msg);
    }
};

vector<Message *> MessageLog::msgLog;

class Player;

class ChatRepository{ // To store the mapping
    static map<string, Player *> chatMap;
public:
    static Player * getReciever(string playerName){
        return chatMap[playerName];
    }
    static void setReciever(string playerName, Player* player){
        chatMap[playerName] = player;
    }
    static void unsetReciever(string playerName){
        chatMap.erase(playerName);
    }
};
map<string, Player *> ChatRepository::chatMap;

class Chat{
public:
    static void connect(string name, Player *player){
        ChatRepository::setReciever(name, player);
    }
    static void disconnect(string name){
        ChatRepository::unsetReciever(name);
    }
    static void chatDispatch(Message *msg);
};

class Player{
    string _name;
public:
    Player(string name): _name(name) {
        // Connect to chatrepo
        Chat::connect(_name, this);
    }
    void send(string reciever, string msgBody){
        Message *msg = new Message(this->_name, reciever, msgBody);
        Chat::chatDispatch(msg);
    }
    void recieve(Message *msg){
        msg->Display();
    }
    ~Player(){
        // Disconnect from chatrepo
        Chat::disconnect(_name);
    }
};

void Chat::chatDispatch(Message *msg){
    (ChatRepository::getReciever(msg->_reciever))->recieve(msg);
    MessageLog::logMsg(msg);
}

int main(){
    Player kapil("kapil");
    Player rahul("rahul");
    kapil.send("rahul", "Hello rahul, kapil here");
    Player sachin("sachin");
    sachin.send("rahul", "Abe! kapil kya bola tereko");
    rahul.send("sachin", "Kuch nhi bro! waise teri kyu jal rhi hai");
    return 0;
}
