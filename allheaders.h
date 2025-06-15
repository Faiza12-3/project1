// al coulours headrers 
// config.h
#ifndef CONFIG_H
#define CONFIG_H
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"
// 🎨 ANSI Color Codes
#define COLOR_RESET       "\033[0m"
#define COLOR_RED         "\033[1;31m"
#define COLOR_GREEN       "\033[1;32m"
#define COLOR_YELLOW      "\033[1;33m"
#define COLOR_BLUE        "\033[1;34m"
#define COLOR_MAGENTA     "\033[1;35m"
#define COLOR_CYAN        "\033[1;36m"
#define COLOR_WHITE       "\033[1;37m"
#define COLOR_BOLD        "\033[1m"
#define COLOR_UNDERLINE   "\033[4m"

// 🎭 Theme Config (optional future use)
#define THEME_DEFAULT     COLOR_CYAN
#define THEME_ALERT       COLOR_RED
#define THEME_SUCCESS     COLOR_GREEN

// 🔧 Constants
#define PI 3.14159265
#define E  2.71828182
#endif
                   
                  //main header
    
 
             
                //dispaywelcome headers
   // ui.h
#ifndef UI_H
#define UI_H
// Function declarations
void displayWelcome();
void clearScreen();
void showMainMenu();
void setColor(const char* colorCode);
void resetColor();

#endif
                     

                      //1file coremath 

#ifndef CORE_MATH_H
#define CORE_MATH_H
void arithmetic_menu();
#endif

                     //2 file academic haeder
#ifndef ACADEMIC_H
#define ACADEMIC_H
#define MAX_SUBJECT_NAME 50  // For handling subject names (optional use in academic.c)
// Function to show academic operations menu
void academic_menu(void);
// Function to calculate GPA
float calculateGPA(int creditHours[], float gradePoints[], int subjects);
// Function to calculate CGPA
float calculateCGPA(float previousCGPA, float currentGPA, int completedSemesters);
#endif
                   
                        // UNITCONVERTER headers

#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H
// Main menu for unit converter
void unit_converter_menu(void);
// Individual unit conversion functions
double convert_length(double value, int from_unit, int to_unit);
double convert_weight(double value, int from_unit, int to_unit);
double convert_temperature(double value, int from_unit, int to_unit);
double convert_speed(double value, int from_unit, int to_unit);
#endif 

                          //modules file header

#ifndef MODULES_H
#define MODULES_H
void modules_menu();
unsigned long long factorial(int n);         // ✅ Add this
int is_prime(int n);                         // ✅ Add this
void solve_quadratic(double a, double b, double c); // ✅ Add this
#endif

                        //ai features headers

#ifndef AI_FEATURES_H
#define AI_FEATURES_H

void simulateVoiceInput();
void chatbotInterface();
void aiPluginPlaceholder();

#endif



                            //history headers

#ifndef HISTORY_H
#define HISTORY_H
// Logs operation and result to history file
void logHistory(const char* operation, double result);
// Views saved history (password protected)
void viewHistory(void);
#endif // HISTORY_H
                            //short game file header

#ifndef LOGIC_H
#define LOGIC_H
void logic_tools_menu();
int get_valid_int(const char *prompt);
#endif
                            //// memory.h
#ifndef MEMORY_H
#define MEMORY_H
void memory_menu();  // 💾 Main memory menu
#endif

