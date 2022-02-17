#pragma once

class ParameterExcept_gl{};

class gluehbirne
{
    private:
    bool licht;
    int helligkeit;

    public:
    gluehbirne();
    gluehbirne(bool m_licht,int m_helligkeit) : licht(m_licht), helligkeit(m_helligkeit) {}

    void an();
    void aus();

    void set_licht(bool li);
    void set_helligkeit(int value);
    int get_helligkeit();
    bool get_licht();
    ~gluehbirne(){}
};
