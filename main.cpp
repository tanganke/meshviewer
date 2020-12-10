#define IGL_VIEWER_VIEWER_QUIET
#include <igl/opengl/glfw/Viewer.h>
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

void meshview(char *file)
{
    igl::opengl::glfw::Viewer viewer;
    igl::opengl::glfw::imgui::ImGuiMenu menu;
    viewer.plugins.push_back(&menu);

    viewer.load_mesh_from_file(file);
    viewer.launch(true, false, file);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "usage:"
                     "\tmeshviewer file1 file2 ..";
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            pid_t pid = fork();
            if (pid == -1)
            {
                std::cerr << "error at: fork()";
                return -1;
            }
            if (pid == 0)
            {
                meshview(argv[i]);
                return 0;
            }
        }
    }

    return 0;
}