class Poly {
protected:
    int coefs[256]; // 계수의 배열

public:
    Poly();
    Poly(int* input, int size);
    Poly(const Poly& o);
    Poly& operator = (const Poly& o);

    void Clear();
    void Init(const int a_coefs[256]);
    void Init(int* input, int size);
    const char* String() const;
    void Mul(const Poly& a, const Poly& b);
    int Eval(int x) const;

};

