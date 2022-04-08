#include <iostream>
#include <cmath>

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

class Rectangle : public Core{
    double width;
    double high;
    Core core;
public:
    Rectangle(int inX,int inY,std::string str,double inWidth,double inHigh)
                :width(inWidth),high(inHigh)
    {
        core.xCenter=inX;
        core.yCenter=inY;
        core.setColor(str);

    }
    void outputArea() {
        std::cout << "Area ";
        printColor(core.color);
        std::cout << " rectangle: " << width * high << std::endl;
    }
    void rectScribe(){
        std::cout<<"Center of circumscribing rectangle (x|y):"<<core.xCenter<<" | "<<core.yCenter<<std::endl;
        std::cout<<"Circumscribing rectangle have\nwidth: "<<width<<" high: "<<high<<std::endl;
    }
    void setRect(int x,int y,double width,double high){
        this->core.xCenter=x;
        this->core.yCenter=y;
        this->width=width;
        this->high=high;
    }

};

class Circle:public Core{
    double radius;
    Core coreCir;
    Rectangle rectCir;
public:
    Circle(int inX,int inY,std::string inStr,double inRadius,Rectangle &rectangle)
                :radius(inRadius),rectCir(rectangle)
    {
        coreCir.xCenter = inX;
        coreCir.yCenter = inY;
        coreCir.setColor(inStr);

    }
    void outputArea() {
        std::cout<<"Area ";
        printColor(coreCir.color);
        std::cout<<" circle: "<< (3.1415*radius*radius)<<std::endl;
    }
    Rectangle scribe(){
        rectCir.setRect(coreCir.xCenter,coreCir.yCenter,radius*2,radius*2);
        return rectCir;
    }
};

class Triangle : public Core{
    double side;
    double h = sqrt(3) * side  / 2;
    Core core;
    Rectangle rectTri;
public:
    Triangle(int inX,int inY,std::string str,double inSide,Rectangle rectangle)
                :side(inSide), rectTri(rectangle)
    {
        core.xCenter=inX;
        core.yCenter=inY;
        core.setColor(str);
    }
    void outputArea() {

        std::cout << "Area ";
        printColor(core.color);
        std::cout << " triangle: " << h * side/2<< std::endl;
    }
    Rectangle scribe(){
        rectTri.setRect(core.xCenter,core.yCenter,side,h);
        return rectTri;
    }
};

class Square : public Core{
    double side;
    Core core;
    Rectangle rectSqu;
public:
    Square(int inX,int inY,std::string str,double inSide,Rectangle rectangle)
                :side(inSide), rectSqu(rectangle)
    {
        core.xCenter=inX;
        core.yCenter=inY;
        core.setColor(str);

    }
    void outputArea(){
        std::cout<<"Area ";
        printColor(core.color);
        std::cout<<" square: "<< side*side <<std::endl;
    }
    Rectangle scribe(){
        rectSqu.setRect(core.xCenter,core.yCenter,side,side);
        return rectSqu;
    }
};


int main() {
    std::string name ;
    int x,y;
    double width,high,side,radius;
    std::string command;
    Rectangle *rectangle=new Rectangle(0,0,"none",0,0);
    do {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "circle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            std::cout<<"Enter circle radius: ";
            std::cin>>radius;
            Circle circle= Circle(x,y,name,radius,*rectangle);
            circle.outputArea();
            *rectangle=circle.scribe();
            rectangle->rectScribe();
        } else if (command == "triangle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            std::cout<<"Enter side size: ";
            std::cin>>side;
            Triangle triangle=Triangle(x, y, name,side,*rectangle);
            triangle.outputArea();
            *rectangle=triangle.scribe();
            rectangle->rectScribe();
        } else if (command == "square") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            std::cout<<"Enter square side length: ";
            std::cin>>side;
            Square square= Square(x, y, name,side,*rectangle);
            square.outputArea();
            *rectangle=square.scribe();
            rectangle->rectScribe();
        } else if (command == "rectangle") {
            std::cout << "Enter center coordinates : ";
            std::cin >> x >> y;
            std::cout << "Enter color: ";
            std::cin >> name;
            std::cout<<"Enter rectangle width: ";
            std::cin>>width;
            std::cout<<"Enter rectangle high:";
            std::cin>>high;
            Rectangle rectangle= Rectangle(x,y,name,width,high);
            rectangle.outputArea();
            rectangle.rectScribe();
        }
    }while(command!="stop");
    delete rectangle;
    return 0;
}
