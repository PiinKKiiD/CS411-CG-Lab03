#include "Painter.h"

//auto& myPainter = Painter::getInstance();

#include <windows.h>
#include <GL/glut.h> 
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
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);   if (value == 1) {
        return; //glutPostRedisplay();
    }
    else if (value == id_HinhTron) {
        glPushMatrix();
        glColor3d(1.0, 0.0, 0.0);
        glutWireSphere(0.5, 50, 50);
        glPopMatrix();
        cout << "Say something here!" << endl;
    }
    else if (value == id_Ellipse) {
        glPushMatrix();
        glColor3d(0.0, 1.0, 0.0);
        glRotated(65, -1.0, 0.0, 0.0);
        glutWireCone(0.5, 1.0, 50, 50);
        glPopMatrix();
    }
    else if (value == id_TgVuongCan) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_TgDeu) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_HinhChuNhat) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_HinhVuong) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_Line) {
        //Line li;
        //li.getInput();
        //myPainter.addShape(li);
    }
    else if (value == id_NguGiacDeu) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_LucGiacDeu) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_NgoiSao) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_MuiTen) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_DauCong) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_DauTru) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_DauNhan) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    else if (value == id_DauChia) {
        glPushMatrix();
        glColor3d(0.0, 0.0, 1.0);
        glutWireTorus(0.3, 0.6, 100, 100);
        glPopMatrix();
    }
    glFlush();
}

void mouse(int button, int state, int x, int y) {

};

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    window = glutCreateWindow("Menus and Submenus - Programming Techniques");
    createMenu();     
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);     
    glutMainLoop();
    return EXIT_SUCCESS;
}