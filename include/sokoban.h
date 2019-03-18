/*
** EPITECH PROJECT, 2018
** sokoban.h
** File description:
** prototypes of sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#define first_cond "board->board[p->line][p->col] == ' '"

typedef struct board_s
{
    char **board;
    int nb_line;
    int *nb_col;
    int max_col;
} board_t;
typedef struct pos_now_s
{
    int line;
    int col;
    int value;
    int stockage;
    int stocks;
} pos_now_t;
typedef struct errors_s
{
    int nb_player;
    int nb_box;
    int nb_stockage;
} errors_t;
typedef struct next_pos_s
{
    int x;
    int y;
    int x2;
    int y2;
} next_pos_t;
int print_usage(void);
int my_sokoban(char *str);
void my_put_map(board_t *map);
void my_put_map_char(int value);
int moves_possible(board_t *map);
void my_error(char const *filepath);
int my_file_size(char const *filepath);
void map_lines(char *str, board_t *map);
int check_char(char c, errors_t *errors);
int check_max_col(int nb_col, int max_col);
char *my_file_readall(char const *filepath);
int is_a_box(board_t *map, int lines, int col);
int box_block(board_t *map, int lines, int col);
void init_player(pos_now_t *player, pos_now_t pos);
char **malloc_char_array(int nb_line, int *nb_col);
next_pos_t init_npos(int x, int y, int x2, int y2);
char **fill_board_zero(char *str, int nb_lin, int *nb_col);
int movable(board_t *map, next_pos_t n, pos_now_t *player);
char **check_error(errors_t errors, char **map, pos_now_t *player);
char **fill_board(char *str, int nb_line, int *nb_col, pos_now_t *player);
void move_up(board_t *board, pos_now_t *p, int stockage, char **map_zero);
void move_down(board_t *board, pos_now_t *p, int stockage, char **map_zero);
void move_left(board_t *board, pos_now_t *p, int stockage, char **map_zero);
void move_right(board_t *board, pos_now_t *p, int stockage, char **map_zero);
int window_loop(board_t *map, pos_now_t *player, char *str, char **map_zero);
void wait_event(board_t *board, pos_now_t *player, char *str, char **map_zer);


#endif
