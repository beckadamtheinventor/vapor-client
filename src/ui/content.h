#ifndef content_h
#define content_h

#include <stddef.h>
#include <stdint.h>
#include <graphx.h>
#include <stdbool.h>
#include "fileaccess.h"

#define gfx_RestoreCanvas() \
        gfx_FillScreen(BG_COLOR)

#define gfx_FillRectangleColor(x, y, w, h, color) \
        gfx_SetColor((color)); \
        gfx_FillRectangle((x), (y), (w), (h));
        
#define gfx_RectangleColor(x, y, w, h, color) \
        gfx_SetColor((color)); \
        gfx_Rectangle((x), (y), (w), (h));
        
#define gfx_PrintUIntXY(int, x, y) \
        gfx_SetTextXY((x), (y)); \
        gfx_PrintUInt((int), num_len(int));
        
#define gfx_PrintUIntSize(int) \
        gfx_PrintUInt((int), num_len(int));
        
#define gfx_FillCircleColor(x, y, r, color) \
        gfx_SetColor(color); \
        gfx_FillCircle((x), (y), (r));

#define BG_COLOR 74
#define IND_COLOR 159
#define NAV_COLOR 181
#define NAV_SELECTED 148
#define TEXT 223
#define ONLINE_COLOR 38
#define OFFLINE_COLOR 224

extern bool queue_update;

extern uint8_t menu_item_selected;
enum _menu_items {
    MENU_NULL,
    MENU_LIBRARY,
    MENU_SERVICES
};

typedef struct _library {
    char name[9];
    uint8_t type;
    uint24_t crc;
} library_t;

void ui_RenderBackground(void);
void ui_ShowLibrary(bool show_upd);
void ui_RenderContent(void);
void lib_Init(void);

uint8_t num_len(uint24_t num);
uint8_t text_WrappedString(char *str, uint24_t left_margin, uint8_t top_margin, uint24_t right_margin);
uint24_t text_CenterText(const char *string, const char c, uint24_t x, uint24_t w);
void gfx_PrintStringCentered(const char* string, uint24_t x, uint8_t y, uint24_t w);

uint24_t rc_crc32(uint32_t crc, const char *buf, size_t len);
void library_update_entry(file_start_t* lib);
uint24_t library_get_crc(const char* string, uint8_t type);

#endif