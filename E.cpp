class Kwama: public Creature{
    protected:
    int age;
    public:
    Kwama (double x, double y, double vx, double vy, int age) : Creature(x, y, vx, vy), age(age) { }
    virtual void act_like_a_kwama() = 0;
    virtual void pouch() = 0;
    virtual unsigned int slaughter() = 0;
};