//
// Created by alisson on 20/08/22.
//
#include "page.h"

//Clase principal para las paginas

//page constructor

page::page(int page1, int page2, int page3, int page4, int page5, int page6) {

    Setpage(page1, page2, page3, page4, page5, page6);

}

//page member function
void page::Setpage(int page1, int page2, int page3, int page4, int page5, int page6) {
    m_page1[256] = page1;
    m_page2[256] = page2;
    m_page3[256] = page3;
    m_page4[256] = page4;
    m_page5[256] = page5;
    m_page6[256] = page6;

}
