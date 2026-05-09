#pragma ocne
#include <string>
#include<stdexcept>

using std::string;

class shape{
private:
    string id;
    double area;

public:
    shape(const string&  );
    virtual ~shape();

    virtual double getArea()=0;//使得类成为纯虚函数类，且纯虚函数必须在显式定义；
    virtual void print()const;
};

class twoDimensionShape: public shape{
    public:
    twoDimensionShape(const string& );

    virtual ~twoDimensionShape();
    virtual double getArea();
    virtual void print()const override;

};

class threeDimensionShape:public shape{
    private:
    double volume;
    
    public:

    threeDimensionShape(const string& );
    virtual ~threeDimensionShape();

    virtual void getVolume();
    virtual void print()const override;
    virtual double getArea()override;
};

class triangle:public twoDimensionShape{
    private:
    double A[2];
    double B[2];
    double C[2];

    public:
    triangle(const string& ,const double[2],const double[2],const double[2]);
    double getArea() override;
    void print()const override;
    ~triangle();
};

class square:public twoDimensionShape{
    private:
    double leftTopDot[2];
    double rightBottomDot[2];

    public:
    square(const string& ,double[2],double[2]);
    double getArea()override;
    void print() const override;
    ~square();


};

class circle:public twoDimensionShape{
    double Dot[2];
    double R;

public:
    circle(const string & ,double,double[2]);
    ~circle();
    double getArea()override;
    void print() const override;
};

class sphere:public threeDimensionShape{
    double Dot[2];
    double R;

public:
    sphere(const string & ,double,double[2]);
    ~sphere();
    double getArea()override;
    void print() const override;
    void getVolume() override;
    void print() const override;
};