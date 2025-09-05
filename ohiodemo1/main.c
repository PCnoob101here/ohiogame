#include <gl/gl.h>
#include <spristnames.h>

void makdisplists()
{
    GLfloat gameverts[] = {
        ///main fur head
        //hidden vert
        0.0f, -0.3f,
        //up
        -1.4f, 0.01f,
        -1.0f, 0.13f,
        -0.5f, 0.15f,
        -0.3f, 0.16f,
        //down
        1.4f, 0.01f,
        1.0f, 0.13f,
        0.5f, 0.15f,
        0.3f, 0.16f,
        ///2 tiny furs
        -0.28f, 0.16f,
        0.02f, 0.16f,
        0.35f, 0.22f,
        
        ///checkbox
        ///button switch

        };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, gameverts);
    glNewList(FURRY_HEAD_C, GL_COMPILE);
    //the vibrant colored part of the head
    glDrawArrays();
    //little detail
    glDrawArrays(GL_TRIANGLES, 9, 6);
    glEndList();
    glNewList(FURRY_HEAD_NC, GL_COMPILE);
    //white head part
    glColor3f(1.0f, 1.0f, 1.0f);
    glDrawArrays();
    //nose
    glColor3f(0.0f, 0.0f, 0.0f);
    glDrawArrays(GL_POLYGON);
    glEndList();
    glNewList(CHECKBOX_ON, GL_COMPILE);
    glColor3f(0.0f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, -0.06f, -0.1f);
    glVertex3f(0.06f, -0.06f, -0.1f);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex3f(-0.05f, -0.05f, 0.05f);
    glVertex3f(0.05f, -0.05f, 0.5f);
    glColor3f(0.0f, 0.9f, 0.0f);
    glVertex3f(0.06f, 0.06f, 0.0f);
    glVertex3f(-0.06f, 0.06f, 0.0f);
    glEnd();
    glEndList();
    glNewList(CHECKBOX_OFF, GL_COMPILE);
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, 0.06f, -0.1f);
    glVertex3f(-0.06f, -0.06f, -0.1f);
    glVertex3f(0.06f, -0.06f, -0.1f);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex3f(-0.05f, -0.05f, 0.05f);
    glVertex3f(0.05f, -0.05f, 0.5f);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex3f(0.06f, 0.06f, 0.0f);
    glVertex3f(-0.06f, 0.06f, 0.0f);
    glEnd();
    glEndList();
}

#define OHIO_SETTINGS_SCREEN
#define OHIO_MAIN_MENU
#define OHIO_GAME

unsigned char gamescreen;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;
        case WM_SIZE:
            glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
            double extracoordspace;
            if(LOWORD(lParam) > HIWORD(lParam))
            {
                extracoordspace = HIWORD(lParam) / (LOWORD(lParam) - HIWORD(lParam)) / 1.0 + 1.0;
                glFrustum(extracoordspace * -1, extracoordspace, -1.0, 1.0, 1.0, -1.0)
            }
            else
            {
                extracoordspace = LOWORD(lParam) / (HIWORD(lParam) - LOWORD(lParam)) / 1.0 + 1.0;
                glFrustum(-1.0, 1.0, extracoordspace * -1, extracoordspace, 1.0, -1.0);
            }
        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (gamescreen)
            {
                case OHIO_GAME:
                    switch(wParam)
                    {
                        case VK_UP:
                        break;
                        case VK_DOWN:
                        break;
                        case VK_LEFT:
                        break;
                        case VK_RIGHT:
                        break;
                        case VK_SPACE:
                        break;
                        case 49:
                        break;
                        case 50:
                        break;
                        case 51:
                        break;
                        case 52:
                        break;
                        case 53:
                        break;
                    }
                break;
                case OHIO_MAIN_MENU:
                    switch(wParam)
                    {
                        case VK_UP;
                        break;
                        case VK_DOWN;
                        break;
                        case VK_SPACE;
                        break;
                    }
                break;
                case OHIO_SETTINGS_SCREEN:
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "escapeohio",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          256,
                          256,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();
            glRotatef(theta, 0.0f, 0.0f, 1.0f);

            glCallList();

            glPopMatrix();

            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}


void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}
