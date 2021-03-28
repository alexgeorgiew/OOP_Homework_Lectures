class Drink {
public:
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);
    ~Drink();
    Drink();
    // Add whatever you deem needed here
private:
    // Add whatever you deem needed herea
    char* name;
    int calories;
    double quantity, price;
    int GetLengthOf(const char* input)const;
    char* Copy(const char* copy)const;
};