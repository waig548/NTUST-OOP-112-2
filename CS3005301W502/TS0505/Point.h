class Point {
    private:
    float* pos;

    public:
    Point();
    Point(const Point& p);
    ~Point();
    void Set(float x, float y);
    void Move(float dx, float dy);
    void Rotate();
    void Reflect();

    float GetHorizontal() const;
    float GetVertical() const;
};