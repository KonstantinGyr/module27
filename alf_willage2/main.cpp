#include <iostream>
#include <vector>

class MiddleBranch {
    std::string alfName ;
public:
    void setName(){
        std::string name;
        std::cout << "Enter elf name ";
        std::cin >> name;
        if (name == "none") {
            alfName="nobody";
        } else {
            alfName=name;
        }

    }
    std::string getName(){
        return alfName;
    }
    bool detectName(std::string name){     //ищем ельфа в доме
       if( this->alfName==name){
           return true;
       }
       else {
           return false;
       }
    }
};

class  BigBranch{
    MiddleBranch middleBranch;
    std::vector<MiddleBranch> mid_branches;
public:
    void setBranch(){
        int mid_br=rand() % 2 + 2;
        mid_branches.clear();
        for(int i=0;i<mid_br;i++) {
            std::cout<< " Branch # " << i+1<<std::endl;
            middleBranch.setName();
            mid_branches.push_back(middleBranch);
        }
    }
    bool getMidBranch(std::string name){     //ищем ельфа на большой ветке
        for(auto item:mid_branches){             //если находим выводим соседей
            if(item.detectName(name)){
                std::cout<<"His neighbors: ";
                for(auto item:mid_branches) {
                    if (item.getName() == "nobody" || item.getName() == name) {
                        continue;
                    }
                    std::cout << item.getName() <<" . ";
                }
                std::cout<<std::endl;
                return true;
            }
        }
        return false;
    }
};

class Tree{
    BigBranch bigBranch;
    std::vector<BigBranch> big_branches;
public:
    void setTree(){
        big_branches.clear();
        int big_br=rand() % 2 + 2;
        for(int i=0;i<big_br;i++) {
            std::cout<< " Big branch #" << i+1;
            bigBranch.setBranch();
            big_branches.push_back(bigBranch);
        }
    }
    bool getBigBranch(std::string name){
        for(auto item:big_branches){
            if(item.getMidBranch(name)){
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::string name;
    Tree tree;
    std::vector<Tree>trees;
    for(int i=0;i<3;i++) {// заселяем эльфов
        std::cout << "Tree # " << i+1;
        tree.setTree();
        trees.push_back(tree);
    }
    std::cout<<"Full house............"<<std::endl;
    std::cout << "Enter elf name: ";     //ищем соседей
    std::cin >> name;
    for(int i=0;i<trees.size();i++) {
        if (!trees[i].getBigBranch(name)) {
            std::cout << "This elf doesn't live on " <<i+1<<" tree\n";
        }
    }
    return 0;
}
