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
        std::cout<<"Enter number of workers in the team # : "<<num<<": ";//создаем бригады
        std::cin>>quant_worker;
        for(int i=0;i<quant_worker;i++){
            worker.setNumWorker(i+1);
            workers.push_back(worker);
        }
    }
    bool setTaskTeam(int task){
        std::srand(task+num);
        taskCount=rand()%(workers.size())+1;//ставим задачу бригаде
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
};

int main() {
    int quant_team;
    Team*team=new Team();
    std::vector<Team> teams;
    std::cout << "Enter teams quantity: ";
    std::cin>> quant_team;
    for(int i=0;i<quant_team;i++){//создаем компанию
        team->setNum(i+1);
        team->setQuant_worker();
        teams.push_back(*team);
    }
    bool full;
    do{
        int task;
        std::cout<<"Set a task ";
        std::cin>>task;
        full=true;
        for(int i=0;i<teams.size();i++) {
            if(!teams[i].setTaskTeam(task)){
                full=false;
            }
        }
    }while(!full);
    delete team;
    return 0;
}
