#ifndef CELL_H
#define CELL_H

#include "fort_impl.h"




/*****************************************************************************
 *               CELL
 * ***************************************************************************/
//struct fort_cell
//{
//    string_buffer_t *str_buffer;
//    fort_table_options_t *options;
//};

fort_cell_t * create_cell();


void destroy_cell(fort_cell_t *cell);
int hint_width_cell(const fort_cell_t *cell, const context_t *context);
int hint_height_cell(const fort_cell_t *cell, const context_t *context);


/*
 * Returns number of lines in cell. If cell is empty or
 * contains empty string, then 0 is returned.
 */
//static int lines_number_cell(fort_cell_t *cell);

int cell_printf(fort_cell_t *cell, size_t row, size_t column, char *buf, size_t buf_len, const context_t *context);

fort_status_t fill_cell_from_string(fort_cell_t *cell, const char *str);

string_buffer_t* cell_get_string_buffer(fort_cell_t *cell);

#endif // CELL_H
