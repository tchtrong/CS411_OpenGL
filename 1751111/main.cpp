//#include "ShapeFactory.h"

#include "Line.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Point.h"
#include "Elipse.h"
#include "RegularPolygon.h"

std::vector<std::unique_ptr<Shape>> list_obj{};

GLsizei windows_witdh = 800;
GLsizei windows_height = 600;

static int menu_id;
static int submenu_tam_giac;
static int submenu_tu_giac;
static int submenu_oval;
static int submenu_da_giac_deu;
static int submenu_hinh_khac;
static int submenu_dau;
static int submenu_to_mau;
static int submenu_chon_hinh;

// Menu items
enum class MENU
{
    DEFAULT = 100,
    duong_thang,
    tg_vc,
    tg_deu,
    circle,
    elipse,
    rectangle,
    square,
    ngu_giac_deu,
    luc_giac_deu,
    that_giac_deu,
    bat_giac_deu,
    cuu_giac_deu,
    thap_giac_deu,
    thap_nhat_giac_deu,
    thap_nhi_giac_deu,
    thap_tam_giac_deu,
    thap_tu_giac_deu,
    thap_ngu_giac_deu,
    thap_luc_giac_deu,
    thap_that_giac_deu,
    thap_bat_giac_deu,
    thap_cuu_giac_deu,
    nhi_thap_giac_deu,
    cong,
    tru,
    nhan,
    chia,
    blue,
    red,
    yellow,
    arrow,
    star,
    chon_hinh,
};

// Assign a default value
MENU show = MENU::DEFAULT;
bool is_drawing = false;

// Menu handling function declaration
void menu_handle(int item)
{
    show = static_cast<MENU>(item);
    return;
}

//Create menu
void create_menu() {
    // Create a menu
    submenu_tam_giac = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Vuong can", static_cast<int>(MENU::tg_vc));
    glutAddMenuEntry("Deu", static_cast<int>(MENU::tg_deu));

    // Create a menu
    submenu_tu_giac = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Hinh chu nhat", static_cast<int>(MENU::rectangle));
    glutAddMenuEntry("Hinh vuong", static_cast<int>(MENU::square));

    // Create a menu
    submenu_oval = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Hinh tron", static_cast<int>(MENU::circle));
    glutAddMenuEntry("Hinh elipse", static_cast<int>(MENU::elipse));

    // Create a menu
    submenu_da_giac_deu = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Ngu giac deu", static_cast<int>(MENU::ngu_giac_deu));
    glutAddMenuEntry("Luc giac deu", static_cast<int>(MENU::luc_giac_deu));
    glutAddMenuEntry("That giac deu", static_cast<int>(MENU::that_giac_deu));
    glutAddMenuEntry("Bat giac deu", static_cast<int>(MENU::bat_giac_deu));
    glutAddMenuEntry("Cuu giac deu", static_cast<int>(MENU::cuu_giac_deu));
    glutAddMenuEntry("Thap giac deu", static_cast<int>(MENU::thap_giac_deu));
    glutAddMenuEntry("Thap nhat giac deu", static_cast<int>(MENU::thap_nhat_giac_deu));
    glutAddMenuEntry("Thap nhi giac deu", static_cast<int>(MENU::thap_nhi_giac_deu));

    // Create a menu
    submenu_hinh_khac = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Mui ten", static_cast<int>(MENU::arrow));
    glutAddMenuEntry("Ngoi sao", static_cast<int>(MENU::star));

    // Create a menu
    submenu_dau = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Cong", static_cast<int>(MENU::cong));
    glutAddMenuEntry("Tru", static_cast<int>(MENU::tru));
    glutAddMenuEntry("Nhan", static_cast<int>(MENU::nhan));
    glutAddMenuEntry("Chia", static_cast<int>(MENU::chia));

    // Create a menu
    submenu_to_mau = glutCreateMenu(menu_handle);
    glutAddMenuEntry("Xanh", static_cast<int>(MENU::blue));
    glutAddMenuEntry("Do", static_cast<int>(MENU::red));
    glutAddMenuEntry("Vang", static_cast<int>(MENU::yellow));

    menu_id = glutCreateMenu(menu_handle);

    // Add menu items
    glutAddMenuEntry("Duong thang", static_cast<int>(MENU::duong_thang));
    glutAddSubMenu("Tam giac", submenu_tam_giac);
    glutAddSubMenu("Tu giac", submenu_tu_giac);
    glutAddSubMenu("Oval", submenu_oval);
    glutAddSubMenu("Da giac deu", submenu_da_giac_deu);
    glutAddSubMenu("Hinh khac", submenu_hinh_khac);
    glutAddSubMenu("Dau", submenu_dau);
    glutAddSubMenu("To mau", submenu_to_mau);
    glutAddMenuEntry("Chon hinh", static_cast<int>(MENU::chon_hinh));

    // Associate a mouse button with menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//Special key event
void special_key_event(int key, int xMousePos, int yMousePos) {
    Shape* cur = list_obj.back().get();
    switch (key)
    {
    case GLUT_KEY_LEFT:
        cur->translate(TRANSLATE::LEFT());
        break;
    case GLUT_KEY_RIGHT:
        cur->translate(TRANSLATE::RIGHT());
        break;
    case GLUT_KEY_UP:
        cur->translate(TRANSLATE::UP());
        break;
    case GLUT_KEY_DOWN:
        cur->translate(TRANSLATE::DOWN());
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//Normal key event
void normal_key_event(unsigned char key, int xMousePos, int yMousePos) {
    Shape* cur = list_obj.back().get();
    switch (key)
    {
    case 'l':
        cur->rotate(ROTATE::COUNTER_CLOCKWISE());
        break;
    case 'r':
        cur->rotate(ROTATE::CLOCKWISE());
        break;
    case '+':
        cur->scale(SCALE::ENLARGE);
        break;
    case '-':
        cur->scale(SCALE::REDUCE);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//Mouse event
void mouse_draw(int button, int state, int xMousePos, int yMousePos) {
    const Point p { { float(xMousePos),float(yMousePos) } };
    const Line l  { p,p };
    switch (show)
    {
    case MENU::DEFAULT:
        break;

    case MENU::duong_thang:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<Line>(l));
                is_drawing = true;
            }
            glutPostRedisplay();
        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            dynamic_cast<Line*>(list_obj[list_obj.size() - 1].get())->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::rectangle:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RecTangle>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            dynamic_cast<RecTangle*>(list_obj[list_obj.size() - 1].get())->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::square:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<Square>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            dynamic_cast<Square*>(list_obj[list_obj.size() - 1].get())->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::circle:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<Circle>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::elipse:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<Elipse>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::tg_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularTriangle>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::luc_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularHexagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::ngu_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularPentagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::that_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularHeptagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::bat_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularOctagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::cuu_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularNonagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::thap_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularDecagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::thap_nhat_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<RegularHendecagon>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    case MENU::thap_nhi_giac_deu:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<Regular_12>(l));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            list_obj[list_obj.size() - 1].get()->update(p);
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;

    /*case MENU::tg_vc:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<TamGiacVC>(Point{ xMousePos,yMousePos }, Point{ xMousePos,yMousePos }));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            dynamic_cast<TamGiacVC*>(list_obj[list_obj.size() - 1].get())->end = Point{ xMousePos,yMousePos };
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;
    */

    case MENU::cong:
        break;
    case MENU::tru:
        break;
    case MENU::nhan:
        break;
    case MENU::chia:
        break;
    case MENU::blue:
        break;
    case MENU::red:
        break;
    case MENU::yellow:
        break;
    case MENU::arrow:
        break;
    /*case MENU::star:
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (!is_drawing) {
                list_obj.emplace_back(std::make_unique<Star>(Point{ xMousePos,yMousePos }, Point{ xMousePos,yMousePos }));
                is_drawing = true;
            }
            glutPostRedisplay();

        }
        else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            dynamic_cast<Star*>(list_obj[list_obj.size() - 1].get())->end = Point{ xMousePos,yMousePos };
            show = MENU::DEFAULT;
            is_drawing = false;
            glutPostRedisplay();
        }
        break;*/
    case MENU::chon_hinh:
        break;
    default:
        break;
    }
}

void mouse_move(int xMousePos, int yMousePos) {
    const Point p{ { float(xMousePos),float(yMousePos) } };
    switch (show)
    {
    case MENU::DEFAULT:
        break;

    case MENU::duong_thang:        
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::rectangle:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::square:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::circle:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::elipse:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::tg_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::ngu_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::luc_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::that_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::bat_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::cuu_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::thap_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::thap_nhat_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    case MENU::thap_nhi_giac_deu:
        list_obj[list_obj.size() - 1].get()->update(p);
        glutPostRedisplay();
        break;

    /*case MENU::tg_vc:
        dynamic_cast<TamGiacVC*>(list_obj[list_obj.size() - 1].get())->end = Point{ xMousePos,yMousePos };
        glutPostRedisplay();
        break;

    case MENU::cong:
        break;
    case MENU::tru:
        break;
    case MENU::nhan:
        break;
    case MENU::chia:
        break;
    case MENU::blue:
        break;
    case MENU::red:
        break;
    case MENU::yellow:
        break;
    case MENU::arrow:
        break;
    case MENU::star:
        dynamic_cast<Star*>(list_obj[list_obj.size() - 1].get())->end = Point{ xMousePos,yMousePos };
        glutPostRedisplay();
        break;
    case MENU::chon_hinh:
        break;*/
    default:
        break;
    }
}

// Set UP the rendering state
void SetupRC(void) {
    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    // Set drawing color to green
    glColor3f(0.0f, 1.0f, 0.0f); 
}

void init() {

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, windows_witdh, windows_height, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Called by GLUT library when the window has chanaged size
void ChangeSize(GLsizei w, GLsizei h) {

    windows_height = h;
    windows_witdh = w;

    init();

    //windows_height = h;
    //windows_witdh = w;

    //// Prevent a divide by zero
    //if (h == 0) h = 1;

    //// Set Viewport to window dimensions
    //glViewport(0, 0, windows_witdh, windows_height);

    //// Reset coordinate system
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    //// Establish clipping volume (LEFT, RIGHT, bottom, top, near, far)
    //const GLint aspectRatio = (GLint)w / (GLint)h;
    //if (w <= h)
    //    glOrtho(0, windows_witdh, windows_height / aspectRatio, 0, 1.0, -1.0);
    //else
    //    glOrtho(0, windows_witdh * GLdouble(aspectRatio), windows_height, 0, 1.0, -1.0);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
}

// Called to draw scene
void RenderScene(void) {

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& shape : list_obj) {
        shape->draw();
    }

    // Flush drawing commands
    glutSwapBuffers();
}

// Main program entry point
int main(int argc, char* argv[]) {

    

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windows_witdh, windows_height);
    glutCreateWindow("Bounce");   

    init();

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    glutMouseFunc(mouse_draw);
    glutMotionFunc(mouse_move);

    glutSpecialFunc(special_key_event);
    glutKeyboardFunc(normal_key_event);

    create_menu();

    SetupRC();

    glutMainLoop();

    return 0;
}