class morse
{
private:
    int _pin;
public:
    morse(int pin);
    morse();
    ~morse();
    void point();
    void trait();
    void espace();
};

morse::~morse()
{
}
