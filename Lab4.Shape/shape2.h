#pragma ocne
#include <string>
#include<stdexcept>

using std::string;

class shape{
protected:
    void printDot(const double A[2])const;
private:
    string id;
    double area;

public:
    shape(const string&  );
    virtual ~shape()=0;
    double setArea(double s);
    double getArea()const;
    virtual void print()const;
};

class twoDimensionShape: public shape{
    public:
    twoDimensionShape(const string& );

    virtual ~twoDimensionShape();

};

class threeDimensionShape:public shape{
    private:
    double volume;
    
    public:
    void setVolume(double);
    threeDimensionShape(const string& );
    virtual ~threeDimensionShape();
    virtual double getVolume() const;
};

class triangle:public twoDimensionShape{
    private:
    double A[2];
    double B[2];
    double C[2];

    public:
    triangle(const string& ,const double[2],const double[2],const double[2]);
    void print()const override;
    ~triangle();
};

class square:public twoDimensionShape{
    private:
    double leftTopDot[2];
    double l;

    public:
    square(const string& ,double[2],double);
    void print() const override;
    ~square();


};

class circle:public twoDimensionShape{
    double Dot[2];
    double R;

public:
    circle(const string & ,double[2],double);
    ~circle();
    void print() const override;
};

class sphere:public threeDimensionShape{
    double Dot[2];
    double R;

public:
    sphere(const string & ,double[2],double);
    ~sphere();
    void print() const override;
    
};