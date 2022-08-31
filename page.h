//
// Created by alisson on 20/08/22.
//

#ifndef TAREAEXTRACLASE1_ALISSONRM_PAGE_H
#define TAREAEXTRACLASE1_ALISSONRM_PAGE_H

#endif //TAREAEXTRACLASE1_ALISSONRM_PAGE_H
#include <iostream>

//Declaraciones de las paginas
class page{
private:
    int m_page1[256];
    int m_page2[256];
    int m_page3[256];
    int m_page4[256];
    int m_page5[256];
    int m_page6[256];


public:
    page(int page1, int page2, int page3, int page4, int page5, int page6);

    void Setpage(int page1, int page2, int page3, int page4, int page5, int page6);

        int getpage1(){return m_page1[256]; }
        int getpage2(){return m_page2[256]; }
        int getpage3(){return m_page3[256]; }
        int getpage4(){return m_page4[256]; }
        int getpage5(){return m_page5[256]; }
        int getpage6(){return m_page6[256]; }

};