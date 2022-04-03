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
    Circle(int inX,int inY,std::string inStr)
    {
        coreCir.xCenter = inX;
        coreCir.yCenter = inY;
        coreCir.setColor(inStr);
        std::cout<<"Enter circle radius: ";
        std::cin>>radius;
    }
    void outputArea() {
        std::cout<<"Area ";
        printColor(coreCir.color);
        std::cout<<" circle: "<< (3.1415*radius*radius)<<std::endl;
    }
    void rectScribe(){
        std::cout<<"Center of circumscribing rectangle (x|y):"<<coreCir.xCenter<<" | "<<coreCir.yCenter<<std::endl;
        std::cout<<"Width: "<<radius*2<<" High: "<<radius*2<<std::endl;
    }
};

class Triangle : public Core{
    double side;
    Core core;
public:
    Triangle(int x,int y,std::string str){
        core.xCenter=x;
        core.yCenter=y;
        core.setColor(str);
        std::cout<<"Enter triangle side length: ";
        std::cin>>side;
    }
    void outputArea() {
        double h = sqrt(3) * side * side / 4;
        std::cout << "Area ";
        printColor(core.color);
        std::cout << " triangle: " << h * side/2<< std::endl;
    }
    void rectScribe() {
        std::cout << "Center of circumscribing rectangle (x|y):" << core.xCenter << " | " << core.yCenter
                  << std::endl;
        std::cout << "Width: " << side << " High: " << sqrt(3) * side * side / 4<<std::endl;
    }
};

class Square : public Core{
    double side;
    Core core;
public:
    Square(int x,int y,std::string str){
        core.xCenter=x;
        core.yCenter=y;
        core.setColor(str);
        std::cout<<"Enter square side length: ";
        std::cin>>side;
    }
    void outputArea(){
        std::cout<<"Area ";
        printColor(core.color);
        std::cout<<" square: "<< side*side <<std::endl;
    }
    void rectScribe()  {
        std::cout << "Center of circumscribing rectangle (x|y):" << core.xCenter << " | " << core.yCenter
                  << std::endl;
        std::cout << "Width: " << side << " High: " << side<<std::endl;
    }
};

class Rectangle : public Core{
    double width;
    double high;
    Core core;
public:
    Rectangle(int x,int y,std::string str){
        core.xCenter=x;
        core.yCenter=y;
        core.setColor(str);
        std::cout<<"Enter rectangle width: ";
        std::cin>>width;
        std::cout<<"Enter rectangle high:";
        std::cin>>high;
    }
    void outputArea() {
        std::cout << "Area ";
        printColor(core.color);
        std::cout << " rectangle: " << width * high << std::endl;
    }
    void rectScribe(){
        std::cout<<"Circumscribing rectangle have\n width: "<<width<<" high: "<<high;
    }
};

int main() {
    std::string name ;
    int x,y;
    std::string command;
    do {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "circle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            Circle circle= Circle(x,y,name);
            circle.outputArea();
            circle.rectScribe();
        } else if (command == "triangle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            Triangle triangle=Triangle(x, y, name);
            triangle.outputArea();
            triangle.rectScribe();
        } else if (command == "square") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            Square square= Square(x, y, name);
            square.outputArea();
            square.rectScribe();
        } else if (command == "rectangle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            Rectangle rectangle= Rectangle(x,y,name);
            rectangle.outputArea();
            rectangle.rectScribe();
        }
    }while(command!="stop");
    return 0;
}
