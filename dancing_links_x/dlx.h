struct dlx_s;

typedef struct dlx_s *dlx_t;

dlx_t dlx_new(); //returns new empty exact cover problem

void dlx_clear(dlx_t dlx); //frees exact cover problem

int dlx_rows(dlx_t dlx); //returns number of rows

int dlx_cols(dlx_t dlx); //returns number of columns

//places a 1 in the given row and column
void dlx_set(dlx_t dlx, int row, int col); 

void dlx_mark_optional(dlx_t dlx, int col); //mark column as optional

int dlx_remove_row(dlx_t p, int row); //removes a row from consideration

int dlx_pick_row(dlx_t dlx, int row);

void dlx_forall_cover
