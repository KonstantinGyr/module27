#include <iostream>
#include <vector>

class HomeAlf{
    std::string name="nobody";
    int numTree=0;
    int numBaseBranch=0;
    int numMiddleBranch=0;
public:
    void setName(std::string name){
        this->name=name;
    }
    void setNumTree(int nT){
        numTree=nT;
    }
    void setNumBase(int nB){
        numBaseBranch=nB;
    }
    void setNumMid(int nM){
        numMiddleBranch=nM;
    }
    std::string getName(){
        return name;
    }
    int getBranch(){
        return numBaseBranch;
    }
};

class Tree{
    int num=0 ;
    std::vector<int> baseBranch;
public:
    int getNum(){
        return num;
    }
    int getMidBranch(int n){
        return baseBranch[n];
    }
    int getBaseBranch(){
        return baseBranch.size();
    }
    void setTree(int num) {
        this->num=num;
        int base = rand() % 3 + 2;
        for (int j = 0; j < base; j++) {
            int x = rand() % 2 + 2;
            baseBranch.push_back(x);
        }
    }
};

int main() {
    std::string name;
    Tree*tree= new Tree();
    Tree trees[3];
    for(int i=0;i<3;++i) {  //создаем деревья
        trees[i].setTree(i);
    }
    HomeAlf *homeAlf=new HomeAlf();
    std::vector<HomeAlf>homes;
    std::cout<<"Let's settle the elves"<<std::endl;
    for(int i=0;i<3;i++) {
        for(int j=0;j<trees[i].getBaseBranch();j++) {
            for(int k=0;k<trees[i].getMidBranch(j);k++) {
                std::cout << "Enter elf name ";// заселяем эльфов
                std::cin >> name;
                if(name=="none"){
                    homeAlf->setName("nobody");
                }
                else {
                    homeAlf->setName(name);
                }
                homeAlf->setNumTree(i);
                homeAlf->setNumBase(j);
                homeAlf->setNumMid(k);
                homes.push_back(*homeAlf);
            }
        }
    }
    std::cout<<"Full house."<<std::endl;
    int branch=-1;
    do {
        std::cout << "Enter elf name: ";
        std::cin >> name;
        for (int i = 0; i < homes.size(); i++) {
            if (homes[i].getName() == name) {
                branch = homes[i].getBranch();
            }
        }
        if(branch==-1){
            std::cout<<"This elf doesn't live here."<<std::endl;
        }
    } while (branch==-1);
    std::cout<<"His neighbors: "<<std::endl;
    for(int i=0;i<homes.size();i++){
        if(branch==homes[i].getBranch()){
            if(homes[i].getName()=="nobody" || homes[i].getName()==name){
                continue;
            }
            std::cout<<homes[i].getName()<<std::endl;
        }
    }
    delete tree;
    delete homeAlf;
    return 0;
}
