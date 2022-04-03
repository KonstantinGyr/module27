#include <iostream>
#include <cstdlib>
#include <vector>

class Worker{
    int num;
    char task;
public:
    void setNumWorker(int num){
        this->num=num;
    }
    bool setTask(char task1){//рабочий берет задачу, если ее нет
        if(task=='0'){
            this->task=task1;
            return true;
        }
        return false;
    }
    Worker():task('0'),num(0){
    }
};

class Team{
    int num;
    Worker worker;
    int quant_worker;
    std::vector<Worker>workers;
    int taskCount;
public:
    void setNum(int num){
        this->num=num;
    }
    void setQuant_worker(){
        workers.clear();
        std::cout<<"Enter number of workers in the team # : "<<num<<": ";//создаем бригады
        std::cin>>quant_worker;
        for(int i=0;i<quant_worker;i++){
            worker.setNumWorker(i+1);
            workers.push_back(worker);
        }
    }
    bool setTaskTeam(int task){//ставим задачу бригаде
        taskCount=task;
        for(int i=0;i<workers.size();i++){
            if(workers[i].setTask(rand()%3+'A')){//ставим задачу рабочему
                taskCount--;
            }
            if(taskCount==0&&i<workers.size()-1){
                return false;
            }
        }
        if(taskCount>=0){
            std::cout<<"In team # "<<num<<" everyone has a task."<<std::endl;
            return true;
        }
        return true;
    }
    int getWorker(){
        return quant_worker;
    }
};
class Manager{
    int num;
    Team team;
public:
    void setTeam(int num){
        this->num=num;
        team.setNum(num);
        team.setQuant_worker();
    }
    bool setTask(int task){
        std::srand(task+num);
        if(team.setTaskTeam(rand()%(team.getWorker())+1)){
            return true;
        }
        else{
            return false;
        }
    }
};

class Director{
    int quant_team;
    bool full;
    Manager manager;
    std::vector<Manager>managers;
public:
    void setMaking() {
        std::cout << "Enter teams quantity: ";
        std::cin >> quant_team;
        for (int i = 0; i < quant_team; i++) {//создаем компанию
            manager.setTeam(i+1);
            managers.push_back(manager);
        }
    }
    void setTask() {
        do {
            int task;
            std::cout << "Set a task ";
            std::cin >> task;
            full = true;             //ставим задачу менеджерам
            for (int i = 0; i < managers.size(); i++) {
                if (!managers[i].setTask(task)) {
                    full = false;
                }
            }
        } while (!full);
    }
};

int main() {
    auto*director=new Director();
    director->setMaking();
    director->setTask();
    delete director;
    return 0;
}

