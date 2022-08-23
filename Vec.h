#include <math.h>
#include <initializer_list>

template<int N> class Vec {
protected:
    float components[N];
public:
    Vec operator+(const Vec& other) const {
        float next[N];
        for(int i = 0; i < N; i++) {
            next[i] = components[i] + other[i];
        }
        return Vec<N>(next);
    }
    void operator+=(const Vec& other) {*this = *this + other;}

    Vec operator-(const Vec& other) const {
        float next[N];
        for(int i = 0; i < N; i++) {
            next[i] = components[i] + other[i];
        }
        return Vec<N>(next);
    }
    void operator-=(const Vec& other) {*this = *this - other;}

    float operator*(const Vec& other) const {  // dot product
    float sum = 0;
        for(int i = 0; i < N; i++) {
            sum += components[i] * other.components[i];
        }
        return sum;
    }

    Vec operator*(float scale) const {
        float next[N];
        for(int i = 0; i < N; i++) {
            next[i] = components[i] * scale;
        }
        return Vec<N>(next);
    }
    void operator*=(float scale) {*this = *this * scale;}

    Vec operator/(float scale) const {
        return *this * (1.0f / scale);
    }
    void operator/=(float scale) {*this = *this / scale;}

    float operator[](unsigned int index) const {return components[index];}
    float magnitudeSquared() const {return (*this) * (*this);}
    float magnitude() const {return sqrt(this->magnitudeSquared());}
    Vec normalized() const {return *this / magnitude();}
    void normalize() {*this = *this / magnitude();}

    Vec() {
        for(int i = 0; i < N; i++) {
            this->components[i] = 0.0f;
        }
    }
    Vec(float input[N]) {
        for(int i = 0; i < N; i++) {
            components[i]=input[i];
        }
    }
    Vec(std::initializer_list<float> components) {
        static_assert(components.size() == N);
        std::copy(components.begin(), components.end(), this->components);
    }
};

class Vec3 : public Vec<3> {
private:
    enum axis {xPos,yPos,zPos};
public:
    Vec3() : Vec<3>{{0,0,0}} {}
    Vec3(float x, float y, float z) : Vec<3>{{x,y,z}} {}
    float x() {return components[xPos];}
    float y() {return components[yPos];}
    float z() {return components[zPos];}
    void x(float x) {components[xPos] = x;}
    void y(float y) {components[yPos] = y;}
    void z(float z) {components[zPos] = z;}
};

class Vec2 : public Vec<2> {
private:
    enum axis {xPos, yPos};
public:
    Vec2() : Vec<2>{{0,0}} {}
    Vec2(float x, float y) : Vec<2>{{x,y}} {}
    float x() {return components[xPos];}
    float y() {return components[yPos];}
    void x(float x) {components[xPos] = x;}
    void y(float y) {components[yPos] = y;}
};

class Color : public Vec3 {
private:
    enum axis {rPos,gPos,bPos};
public:
    Color() {}
    Color(float r, float g, float b) : Vec3(r,g,b) {}
    float r() {return components[rPos];}
    float g() {return components[gPos];}
    float b() {return components[bPos];}
    void r(float r) {components[rPos] = r;}
    void g(float g) {components[gPos] = g;}
    void b(float b) {components[bPos] = b;}
};