#include "Painter.h"
#include "Oval.h"
#include "Line.h"
#include "Dagiacdeu.h"
#include "Dau.h"
#include "Tamgiac.h"
#include "Tugiac.h"
#include <windows.h>
#include "glut.h"

static int window;
static int menu_id;
static int submenu_id;
static int value = 0;

static int submenu_oval_id;
static int submenu_tamgiac_id;
static int submenu_tugiac_id;
static int submenu_dagiacdeu_id;
static int submenu_hinhkhac_id;
static int submenu_dau_id;


Painter* myPainter = Painter::getInstance();
Point tempPointStart;
Point tempPointEnd;

void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    }
    else {
        value = num;
    }
    glutPostRedisplay();
}
void createMenu(void) {
    //Layout (tang 3)
    //Oval
    submenu_oval_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh tron", id_HinhTron);
    glutAddMenuEntry("Ellipse", id_Ellipse);

    //TamGiac
    submenu_tamgiac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Vuong Can", id_TgVuongCan);
    glutAddMenuEntry("Deu", id_TgDeu);
    //Tugiac
    submenu_tugiac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh Chu Nhat", id_HinhChuNhat);
    glutAddMenuEntry("Hinh Vuong", id_HinhVuong);

    //dagiacdeu
    submenu_dagiacdeu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngu Giac Deu", id_NguGiacDeu);
    glutAddMenuEntry("Luc Giac Deu", id_LucGiacDeu);
    //hinhkhac
    submenu_hinhkhac_id = glutCreateMenu(menu);
    glutAddMenuEntry("Ngoi Sao", id_NgoiSao);
    glutAddMenuEntry("Mui Ten", id_MuiTen);
    //dau
    submenu_dau_id = glutCreateMenu(menu);
    glutAddMenuEntry("Cong", id_DauCong);
    glutAddMenuEntry("Tru", id_DauTru);
    glutAddMenuEntry("Nhan", id_DauNhan);
    glutAddMenuEntry("Chia", id_DauChia);

    //

    submenu_id = glutCreateMenu(menu);

    //Layout subMenu (Tang 2)
    glutAddSubMenu("Oval", submenu_oval_id);
    glutAddSubMenu("Tam Giac", submenu_tamgiac_id);

    glutAddSubMenu("Tu Giac", submenu_tugiac_id);
    glutAddMenuEntry("Line", id_Line);
    glutAddSubMenu("Da Giac Deu", submenu_dagiacdeu_id);
    glutAddSubMenu("Hinh Khac", submenu_hinhkhac_id);
    glutAddSubMenu("Dau", submenu_dau_id);

    //Layout Menu (tang 1)
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);   
    if (value == 1) {
        return; //glutPostRedisplay();
    }
    for (int i = 0; i < myPainter->getList().size(); i++) {
        cout<<myPainter->getList()[i]->getType()<<endl;
        myPainter->getList()[i]->draw();
    }
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    // Save the left button state
    if (button == GLUT_LEFT_BUTTON && value >0)
    {
        if (state == GLUT_DOWN) {
            tempPointStart.setCoor(x, y);
        }
        if (state == GLUT_UP) {
            tempPointEnd.setCoor(x, y);
            switch (value)
            {
            case id_HinhTron: {
                Shape* a;
                a = new HinhTron(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                break;
            }
            case id_Ellipse: {
                Shape* a;
                a = new HinhElip(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                break;
            }
            case id_TgVuongCan: {
                break;
            }
            case id_TgDeu: {
                break;
            }
            case id_HinhChuNhat: {
                break;
            }
            case id_HinhVuong: {
                break;
            }
            case id_Line: {
                Shape* a;
                a = new Line(tempPointStart, tempPointEnd);
                myPainter->addShape(a);
                break;
            }
            case id_NguGiacDeu: {
                break;
            }
            case id_LucGiacDeu: {
                break;
            }
            case id_NgoiSao: {
                break;
            }
            case id_MuiTen: {
                break;
            }
            case id_DauCong: {
                break;
            }
            case id_DauTru: {
                break;
            }
            case id_DauNhan: {
                break;
            }
            case id_DauChia: {
                break;
            }
            default:
                break;
            }
            myPainter->showList();
        }
    }
    glutPostRedisplay();
    // Save the mouse position

}
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 500, 0);
    glColor3f(0, 0, 1); // blue
    glPointSize(5); //size
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("Menus and Submenus - Programming Techniques");
    init();
    createMenu();     
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return EXIT_SUCCESS;
}