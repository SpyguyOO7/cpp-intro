#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>
#include "Point.hpp"
/*
class Point
{
public:
  Point (double a, double b){
    x = a;
    y = b;
  }
  double x;
  double y;
  double distance_to_origin(){
    double distance = sqrt(pow(x,2)+pow(y,2));
    return distance;
  }
  double distance_to_point(Point b){
    double xDiff = abs(x - b.x);
    double yDiff = abs(y - b.y);
    Point diff(xDiff,yDiff);
    return diff.distance_to_origin();
  }
};
*/
class Triangle
{
public:
  Point p1;
  Point p2;
  Point p3;
  Triangle(Point p1, Point p2,Point p3) : p1(p1), p2(p2), p3(p3){};
  double area(){

    double a = p1.distance_to_point(p2);
    double b = p2.distance_to_point(p3);
    double c = p3.distance_to_point(p1);
    double s = (a + b + c)/2;

    return sqrt(s*(s-a)*(s-b)*(s-c));
  }



};

class Line
{
public:
  double slope;
  Line(Point p1, Point p2) : p1(p1), p2(p2){};
  
  double length(){
    return p1.distance_to_point(p2);
  }
  double distance_to_point(Point C){
    double slope = ((double)p1.x() - (double)p2.y())/((double)p1.x() - (double)p2.x());
    double a = 1;
    double b = a/slope*-1;
    double c = p1.y() - slope*p1.x();

    double distance = abs(a*C.x()+b*C.y()+c)/ sqrt(pow(a,2)+pow(b,2));
    //Point transP1(cos(angle)*xDist,sin(angle)*yDist);
    //Point transP(cos(angle)*xDist,sin(angle)*yDist);

    
    return(distance);
  }


  Point p1;
  Point p2;
};

class Polygon
{
public:
  //std::vector<Point> points;

//public:
  std::vector<Point> points;
  double area(){
    //std::vector<Triangle> triangles;
    double area = 0;
    for (int i = 2; i < points.size(); i++){
      Triangle triangleTemp(points[0],points[i-1],points[i]);
      //triangles.push_back(triangleTemp);
      area = triangleTemp.area()+area;
    }
    return (area);
  }

    double perimeter(){
      double perimeter = 0;
      for (int i = 1; i < points.size(); i++){
        Line lineTemp(points[i-1],points[i]);
      //triangles.push_back(triangleTemp);
        perimeter = lineTemp.length()+perimeter;
      }
      Line lineTemp(points[0],points[points.size()]);
      perimeter = lineTemp.length()+perimeter;
      return (perimeter);
    }
    
  


};
class Circle
{
public:
  int radius;
  Circle(int r){
    radius = r;
  }
  
  double area(){
    return (pow(radius,2)*M_PI);
  }

}; 

class AUV
{
public:
  std::string name;
  Point Position;
  double depth;
  double heading;
  std::array<double,3> speed;
  double angular_speed;
  
  void step(double dt){
    Position.set_x(speed[0]*dt);
    Position.set_y(speed[1]*dt);
    depth += speed[2]*dt;
    heading += angular_speed*dt;
  }
  void apply_accleration (std::array<double, 3> accelerate, double dt){
    speed[0] += accelerate[0]*dt;
    speed[1] += accelerate[1]*dt;
    speed[2] += accelerate[2]*dt;
  }
  void apply_angular_accleration(double angular_accleration, double dt){
    angular_speed += angular_accleration*dt;
  }
};

int add(int x, int y){
  return x + y;
}

int subtract(int x, int y){
  return x - y;
}

int multiply(int x, int y){
  return x * y;
}

int divide(int x, int y){
  return x/y;
}

int main()
{
  std::cout << "William Gao, AUV" << std::endl;

  int x = 5;
  int y = 7;
  int z = 15;
  int v = 8;
  double divResult = (double)(x + y )/ (double)v;

  //int p=1;

  std::cout << "The sum of " << x << " and " << y << " is " << x + y << std::endl;
  std::cout << "The sum of " << x << ", " << y << ", and "<< z <<" is " << x + y + z << std::endl;
  std::cout << "The sum of " << x << " and " << y << " divided by "<< v <<" is " <<   divResult<< std::endl;
  std::cout << "The sum of " << x << " and " << y << " added using the add function is "<< add(x,y) <<std::endl;
  std::cout << "The difference of " << x << " and " << y << " subtracted using the subtract function is "<< subtract(x,y) <<std::endl;
  std::cout << "The product of " << x << " and " << y << " multiplied using the multiply function is "<< multiply(x,y) <<std::endl;
  std::cout << "The dividend of " << x << " and " << y << " divided using the divide function is "<< divide(x,y) <<std::endl;

  //int ok = 1;

  Circle circleObj(5);
  std::cout << "The cirlce of radius " << circleObj.radius << " has an area of  " << circleObj.area() << std::endl;

  Point pointA(3,4);
  Point pointB(-5,-4);
  Point pointC(-4,60);
  std::cout << "The Point A with (" << pointA.x() << ", " << pointA.y() <<") has a distance form the origion of "<< pointA.distance_to_origin() << std::endl;
  std::cout << "The Point B with (" << pointB.x() << ", " << pointB.y() <<") has a distance form the origion of "<< pointB.distance_to_origin() << std::endl;
  //std::cout << "The Point A and Point B have a distance between them of (" << pointA.distance_to_point(pointB) << std::endl;
  Line lineA(pointA,pointB);
  std::cout << "The LineA made up of pointA and pointB has a length of " << lineA.length() << std::endl;
  std::cout << "The Point C with (" << pointC.x() << ", " << pointC.y() <<") has a distance form the origion of "<< pointC.distance_to_origin() << std::endl;
  std::cout << "The LineA is  " << lineA.distance_to_point(pointC) << " from point C"<<std::endl;
  Triangle triangleA(pointA,pointB,pointC);
  std::cout << "The Triangle has verticies Point A, B, and C, and an area of " << triangleA.area() << " or using heights (verify distance to line is working, valuse should be same)"<< lineA.distance_to_point(pointC) * lineA.length() * .5<<std::endl;
  Polygon polygonA;
  polygonA.points.push_back(pointA);
  polygonA.points.push_back(pointB);
  polygonA.points.push_back(pointC);
  std::cout << "The polygon has verticies Point A, B, and C, and an area of " << polygonA.area() <<", and a perimeter of " << polygonA.perimeter() <<std::endl;
  return 0;
}
