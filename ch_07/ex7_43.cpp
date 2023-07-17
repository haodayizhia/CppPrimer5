class NoDefault {
   public:
    NoDefault(int){};
};

class C {
   public:
    C() : data(0) {}

   private:
    NoDefault data;
};
