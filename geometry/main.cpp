#include <iostream>

enum Colors{
    NONE,
    RED,
    BLUE,
    GREEN,
};

void  printColor(Colors color){
    switch(color){
        case 0:std::cout<<"colorless";break;
        case 1:std::cout<<"red";break;
        case 2:std::cout<<"blue";break;
        case 3:std::cout<<"green";break;
    }
}

class Core{
public:
    int xCenter;
    int yCenter;
    Colors color=NONE;
    void setColor(std::string str) {
        if(str=="red")color = RED;
        else if(str=="blue")color = BLUE;
        else if(str=="green")color = GREEN;
        else{
            color=NONE;
        }
    }
};

class Circle:public Core{
    double radius;
    Core coreCir;
public:
    void setDataCircle(int x,int y,std::string str){
        coreCir.xCenter=x;
        coreCir.yCenter=y;
        coreCir.setColor(str);
        std::cout<<"Enter circle radius: ";
        std::cin>>radius;
    }
    void outputParameters(){
        std::cout<<"Area ";
        printColor(coreCir.color);
        std::cout<<" circle: "<< (3.1415*radius*radius)<<std::endl;
        std::cout<<"Angle coordinates of circumscribing rectangle (x|y):"<<std::endl;
        std::cout << coreCir.xCenter - radius << " | " << coreCir.yCenter + radius << " , ";
        std::cout << coreCir.xCenter + radius << " | " << coreCir.yCenter + radius << " , ";
        std::cout << coreCir.xCenter + radius << " | " << coreCir.yCenter - radius << " , ";
        std::cout << coreCir.xCenter - radius << " | " << coreCir.yCenter - radius << std::endl;
    }
};

class Triangle : public Core{
    double side;
    Core core;
public:
    void setDataTriangle(int x,int y,std::string str){
        core.xCenter=x;
        core.yCenter=y;
        core.setColor(str);
        std::cout<<"Enter triangle side length: ";
        std::cin>>side;
    }
    void outputParameters(){
        double h=sqrt(3)*side*side/4;
        std::cout<<"Area ";
        printColor(core.color);
        std::cout<<" triangle: "<< h <<std::endl;
        std::cout<<"Angle coordinates of circumscribing rectangle (x|y):"<<std::endl;
        std::cout<<core.xCenter-side/2<<" | "<<core.yCenter+h*2/3<<" , ";
        std::cout<<core.xCenter+side/2<<" | "<<core.yCenter+h*2/3<<" , ";
        std::cout<<core.xCenter+side/2<<" | "<<core.yCenter-h/3<<" , ";
        std::cout<<core.xCenter-side/2<<" | "<<core.yCenter-h/3<<std::endl;
    }
};

class Square : public Core{
    double side;
    Core core;
public:
    void setDataSquare(int x,int y,std::string str){
        core.xCenter=x;
        core.yCenter=y;
        core.setColor(str);
        std::cout<<"Enter square side length: ";
        std::cin>>side;
    }
    void outputParameters(){
        std::cout<<"Area ";
        printColor(core.color);
        std::cout<<" square: "<< side*side <<std::endl;
        std::cout<<"Angle coordinates of circumscribing rectangle (x|y):"<<std::endl;
        std::cout<<core.xCenter-side/2<<" | "<<core.yCenter+side/2<<" , ";
        std::cout<<core.xCenter+side/2<<" | "<<core.yCenter+side/2<<" , ";
        std::cout<<core.xCenter+side/2<<" | "<<core.yCenter-side/2<<" , ";
        std::cout<<core.xCenter-side/2<<" | "<<core.yCenter-side/2<<std::endl;
    }
};

class Rectangle : public Core{
    double width;
    double high;
    Core core;
public:
    void setDataRectangle(int x,int y,std::string str){
        core.xCenter=x;
        core.yCenter=y;
        core.setColor(str);
        std::cout<<"Enter rectangle width: ";
        std::cin>>width;
        std::cout<<"Enter rectangle high:";
        std::cin>>high;
    }
    void outputParameter(){
        std::cout<<"Area ";
        printColor(core.color);
        std::cout<<" rectangle: "<< width*high <<std::endl;
        std::cout<<"Angle coordinates of circumscribing rectangle (x|y):"<<std::endl;
        std::cout<<core.xCenter-width/2<<" | "<<core.yCenter+high/2<<" , ";
        std::cout<<core.xCenter+width/2<<" | "<<core.yCenter+high/2<<" , ";
        std::cout<<core.xCenter+width/2<<" | "<<core.yCenter-high/2<<" , ";
        std::cout<<core.xCenter-width/2<<" | "<<core.yCenter-high/2<<std::endl;
    }
};

int main() {
    std::string name ;
    int x,y;
    Circle*circle=new Circle();
    Triangle*triangle=new Triangle();
    Square*square=new Square;
    Rectangle*rectangle=new Rectangle;
    std::string command;
    do {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "circle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            circle->setDataCircle(x, y, name);
            circle->outputParameters();
        } else if (command == "triangle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            triangle->setDataTriangle(x, y, name);
            triangle->outputParameters();
        } else if (command == "square") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            square->setDataSquare(x, y, name);
            square->outputParameters();
        } else if (command == "rectangle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            rectangle->setDataRectangle(x, y, name);
            rectangle->outputParameter();
        }
    }while(command!="stop");
    delete circle;
    delete triangle;
    delete square;
    delete rectangle;
    return 0;
}
