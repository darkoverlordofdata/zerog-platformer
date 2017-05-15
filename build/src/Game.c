/* Game.c generated by valac 0.34.8, the Vala compiler
 * generated from Game.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <SDL2/SDL_rect.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_pixels.h>
#include <SDL_ttf.h>
#include <SDL2/SDL_rwops.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_scancode.h>


#define TYPE_VECTOR2D (vector2d_get_type ())
typedef struct _Vector2d Vector2d;

#define TYPE_SEGMENT (segment_get_type ())
typedef struct _Segment Segment;
typedef struct _Game Game;
typedef struct _Map Map;

#define TYPE_CAMERA_TYPE (camera_type_get_type ())

#define TYPE_POINT2D (point2d_get_type ())
typedef struct _Point2d Point2d;
typedef struct _Systems Systems;

#define TYPE_ENTITY (entity_get_type ())

#define TYPE_CATEGORY (category_get_type ())

#define TYPE_ACTOR (actor_get_type ())

#define TYPE_SPRITE (sprite_get_type ())
typedef struct _Sprite Sprite;

#define TYPE_TIMER (timer_get_type ())
typedef struct _Timer Timer;

#define TYPE_HEALTH (health_get_type ())
typedef struct _Health Health;
typedef struct _Entity Entity;
#define _TTF_CloseFont0(var) ((var == NULL) ? NULL : (var = (TTF_CloseFont (var), NULL)))
#define _SDL_FreeRW0(var) ((var == NULL) ? NULL : (var = (SDL_FreeRW (var), NULL)))
void map_release (Map* self);
void map_free (Map* self);
Map* map_retain (Map* self);
#define _map_release0(var) ((var == NULL) ? NULL : (var = (map_release (var), NULL)))
#define _SDL_FreeSurface0(var) ((var == NULL) ? NULL : (var = (SDL_FreeSurface (var), NULL)))
#define _SDL_DestroyTexture0(var) ((var == NULL) ? NULL : (var = (SDL_DestroyTexture (var), NULL)))
void systems_release (Systems* self);
void systems_free (Systems* self);
Systems* systems_retain (Systems* self);
#define _systems_release0(var) ((var == NULL) ? NULL : (var = (systems_release (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define TYPE_INPUT (input_get_type ())

struct _Vector2d {
	gdouble x;
	gdouble y;
};

struct _Segment {
	SDL_Rect source;
	SDL_Rect dest;
	SDL_RendererFlip flip;
};

typedef Segment* (*SpriteBuilder) (gint x, gint y, int* result_length1, void* user_data);
typedef enum  {
	CAMERA_TYPE_fluidCamera,
	CAMERA_TYPE_innerCamera,
	CAMERA_TYPE_simpleCamera
} CameraType;

struct _Point2d {
	gdouble x;
	gdouble y;
};

typedef enum  {
	CATEGORY_BACKGROUND = 0,
	CATEGORY_BULLET = 1,
	CATEGORY_ENEMY = 2,
	CATEGORY_EXPLOSION = 3,
	CATEGORY_PARTICLE = 4,
	CATEGORY_PLAYER = 5
} Category;

typedef enum  {
	ACTOR_DEFAULT = 0,
	ACTOR_BACKGROUND = 1,
	ACTOR_TEXT = 2,
	ACTOR_LIVES = 3,
	ACTOR_ENEMY1 = 4,
	ACTOR_ENEMY2 = 5,
	ACTOR_ENEMY3 = 6,
	ACTOR_PLAYER = 7,
	ACTOR_BULLET = 8,
	ACTOR_EXPLOSION = 9,
	ACTOR_BANG = 10,
	ACTOR_PARTICLE = 11,
	ACTOR_HUD = 12
} Actor;

struct _Sprite {
	SDL_Texture* texture;
	gint width;
	gint height;
};

struct _Timer {
	gint begin;
	gint finish;
	gint best;
};

struct _Health {
	gint curHealth;
	gint maxHealth;
};

struct _Entity {
	gint id;
	gchar* name;
	gboolean active;
	Category category;
	Actor actor;
	Point2d position;
	SDL_Rect bounds;
	Sprite sprite;
	Vector2d* scale;
	SDL_Color* tint;
	Timer* expires;
	Health* health;
	Vector2d* velocity;
};

struct _Game {
	gint retainCount__;
	gboolean* inputs;
	gint inputs_length1;
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_RWops* font_rw;
	SDL_Event evt;
	Map* map;
	Vector2d camera;
	CameraType cameraType;
	Point2d pos;
	SDL_Surface* playerSurface;
	SDL_Texture* playerTexture;
	SDL_Texture* grassTexture;
	Systems* system;
	Entity* entities;
	gint entities_length1;
};

typedef enum  {
	INPUT_none,
	INPUT_left,
	INPUT_right,
	INPUT_jump,
	INPUT_restart,
	INPUT_quit
} Input;



#define TILES_PER_ROW 16
GType vector2d_get_type (void) G_GNUC_CONST;
Vector2d* vector2d_dup (const Vector2d* self);
void vector2d_free (Vector2d* self);
#define AIR 0
#define START 78
#define FINISH 110
#define PLAYER_PNG "assets/player.bmp"
#define GRASS_PNG "assets/grass.bmp"
#define DEFAULT_MAP "assets/default.map"
#define FONT_TTF "assets/OpenDyslexic-Bold.otf"
GType segment_get_type (void) G_GNUC_CONST;
Segment* segment_dup (const Segment* self);
void segment_free (Segment* self);
void game_release (Game* self);
Game* game_retain (Game* self);
void game_free (Game* self);
void map_release (Map* self);
Map* map_retain (Map* self);
void map_free (Map* self);
GType camera_type_get_type (void) G_GNUC_CONST;
GType point2d_get_type (void) G_GNUC_CONST;
Point2d* point2d_dup (const Point2d* self);
void point2d_free (Point2d* self);
void systems_release (Systems* self);
Systems* systems_retain (Systems* self);
void systems_free (Systems* self);
GType entity_get_type (void) G_GNUC_CONST;
GType category_get_type (void) G_GNUC_CONST;
GType actor_get_type (void) G_GNUC_CONST;
GType sprite_get_type (void) G_GNUC_CONST;
Sprite* sprite_dup (const Sprite* self);
void sprite_free (Sprite* self);
GType timer_get_type (void) G_GNUC_CONST;
Timer* timer_dup (const Timer* self);
void timer_free (Timer* self);
GType health_get_type (void) G_GNUC_CONST;
Health* health_dup (const Health* self);
void health_free (Health* self);
Entity* entity_dup (const Entity* self);
void entity_free (Entity* self);
void entity_copy (const Entity* self, Entity* dest);
void entity_destroy (Entity* self);
static void game_instance_init (Game * self);
static void _vala_Entity_array_free (Entity* array, gint array_length);
Game* game_retain (Game* self);
void game_release (Game* self);
void game_release (Game* self);
Game* game_retain (Game* self);
void game_free (Game* self);
Game* game_new (SDL_Renderer* renderer);
SDL_Texture* loadTexture (SDL_Renderer* renderer, const gchar* path);
SDL_Texture* buildSprite (SDL_Renderer* renderer, SDL_Surface* source, SpriteBuilder builder, void* builder_target, gint h, gint w);
Segment* playerSegments (gint x, gint y, int* result_length1);
static Segment* _playerSegments_sprite_builder (gint x, gint y, int* result_length1, gpointer self);
void sdlFailIf (gboolean cond, const gchar* reason);
Map* map_new (SDL_Texture* texture, const gchar* filename);
void CreatePlayer (SDL_Texture* texture, gint h, gint w, Entity* result);
Systems* systems_new (Game* game);
void game_draw (Game* self, Entity* entity);
void game_draw_text (Game* self, Entity* entity, gint tick);
void game_render_text (Game* self, const gchar* text, gint x, gint y, SDL_Color foreColor);
gchar* formatTime (gint ticks);
void game_render (Game* self, gint tick);
void map_render (Map* self, SDL_Renderer* renderer, Vector2d* camera);
SDL_Color color (guint8 r, guint8 g, guint8 b, guint8 a);
void renderText (SDL_Renderer* renderer, TTF_Font* font, const gchar* text, gint x, gint y, int outline, SDL_Color color);
void game_update (Game* self, gint tick);
void systems_physics (Systems* self, Entity* player, gint tick);
void systems_camera (Systems* self, Entity* player, gint tick);
void systems_logic (Systems* self, Entity* player, gint tick);
GType input_get_type (void) G_GNUC_CONST;
Input game_toInput (Game* self, SDL_Scancode key);
void game_handleInput (Game* self);

const SDL_Point WINDOW_SIZE = {1280, 720};
const SDL_Point TILES_SIZE = {64, 64};
const Vector2d PLAYER_SIZE = {(gdouble) 64, (gdouble) 64};
const SDL_Color WHITE = {(guint8) 255, (guint8) 255, (guint8) 255, (guint8) 255};

static void _vala_Entity_array_free (Entity* array, gint array_length) {
	if (array != NULL) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			entity_destroy (&array[i]);
		}
	}
	g_free (array);
}


Game* game_retain (Game* self) {
	Game* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->retainCount__), 1);
	result = self;
	return result;
}


void game_release (Game* self) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->retainCount__));
	if (_tmp0_) {
		game_free (self);
	}
}


static Segment* _playerSegments_sprite_builder (gint x, gint y, int* result_length1, gpointer self) {
	Segment* result;
	result = playerSegments (x, y, result_length1);
	return result;
}


Game* game_new (SDL_Renderer* renderer) {
	Game* self;
	SDL_Renderer* _tmp0_ = NULL;
	SDL_Renderer* _tmp1_ = NULL;
	SDL_Texture* _tmp2_ = NULL;
	SDL_Surface* _tmp3_ = NULL;
	SDL_Renderer* _tmp4_ = NULL;
	SDL_Surface* _tmp5_ = NULL;
	SDL_Texture* _tmp6_ = NULL;
	gboolean* _tmp7_ = NULL;
	SDL_RWops* _tmp8_ = NULL;
	SDL_RWops* _tmp9_ = NULL;
	TTF_Font* _tmp10_ = NULL;
	TTF_Font* _tmp11_ = NULL;
	SDL_Texture* _tmp12_ = NULL;
	Map* _tmp13_ = NULL;
	SDL_Texture* _tmp14_ = NULL;
	Entity _tmp15_ = {0};
	Entity* _tmp16_ = NULL;
	Systems* _tmp17_ = NULL;
	g_return_val_if_fail (renderer != NULL, NULL);
	self = g_slice_new0 (Game);
	game_instance_init (self);
	_tmp0_ = renderer;
	self->renderer = _tmp0_;
	_tmp1_ = renderer;
	_tmp2_ = loadTexture (_tmp1_, GRASS_PNG);
	_SDL_DestroyTexture0 (self->grassTexture);
	self->grassTexture = _tmp2_;
	_tmp3_ = IMG_Load (PLAYER_PNG);
	_SDL_FreeSurface0 (self->playerSurface);
	self->playerSurface = _tmp3_;
	_tmp4_ = renderer;
	_tmp5_ = self->playerSurface;
	_tmp6_ = buildSprite (_tmp4_, _tmp5_, _playerSegments_sprite_builder, NULL, 96, 96);
	_SDL_DestroyTexture0 (self->playerTexture);
	self->playerTexture = _tmp6_;
	_tmp7_ = g_new0 (gboolean, 6);
	self->inputs = (g_free (self->inputs), NULL);
	self->inputs = _tmp7_;
	self->inputs_length1 = 6;
	_tmp8_ = SDL_RWFromFile (FONT_TTF, "r");
	_SDL_FreeRW0 (self->font_rw);
	self->font_rw = _tmp8_;
	_tmp9_ = self->font_rw;
	_tmp10_ = TTF_OpenFontRW (_tmp9_, 0, 28);
	_TTF_CloseFont0 (self->font);
	self->font = _tmp10_;
	_tmp11_ = self->font;
	sdlFailIf (_tmp11_ == NULL, "Failed to load font");
	_tmp12_ = self->grassTexture;
	_tmp13_ = map_new (_tmp12_, DEFAULT_MAP);
	_map_release0 (self->map);
	self->map = _tmp13_;
	self->cameraType = CAMERA_TYPE_simpleCamera;
	_tmp14_ = self->playerTexture;
	CreatePlayer (_tmp14_, 96, 96, &_tmp15_);
	_tmp16_ = g_new0 (Entity, 1);
	_tmp16_[0] = _tmp15_;
	self->entities = (_vala_Entity_array_free (self->entities, self->entities_length1), NULL);
	self->entities = _tmp16_;
	self->entities_length1 = 1;
	_tmp17_ = systems_new (self);
	_systems_release0 (self->system);
	self->system = _tmp17_;
	return self;
}


void game_draw (Game* self, Entity* entity) {
	gdouble x = 0.0;
	Entity _tmp0_ = {0};
	Point2d _tmp1_ = {0};
	gdouble _tmp2_ = 0.0;
	Vector2d _tmp3_ = {0};
	gdouble _tmp4_ = 0.0;
	gdouble y = 0.0;
	Entity _tmp5_ = {0};
	Point2d _tmp6_ = {0};
	gdouble _tmp7_ = 0.0;
	Vector2d _tmp8_ = {0};
	gdouble _tmp9_ = 0.0;
	gint h = 0;
	Entity _tmp10_ = {0};
	Sprite _tmp11_ = {0};
	gint _tmp12_ = 0;
	gint w = 0;
	Entity _tmp13_ = {0};
	Sprite _tmp14_ = {0};
	gint _tmp15_ = 0;
	SDL_Renderer* _tmp16_ = NULL;
	Entity _tmp17_ = {0};
	Sprite _tmp18_ = {0};
	SDL_Texture* _tmp19_ = NULL;
	SDL_Rect _tmp20_ = {0};
	g_return_if_fail (self != NULL);
	g_return_if_fail (entity != NULL);
	_tmp0_ = *entity;
	_tmp1_ = _tmp0_.position;
	_tmp2_ = _tmp1_.x;
	_tmp3_ = self->camera;
	_tmp4_ = _tmp3_.x;
	x = _tmp2_ - _tmp4_;
	_tmp5_ = *entity;
	_tmp6_ = _tmp5_.position;
	_tmp7_ = _tmp6_.y;
	_tmp8_ = self->camera;
	_tmp9_ = _tmp8_.y;
	y = _tmp7_ - _tmp9_;
	_tmp10_ = *entity;
	_tmp11_ = _tmp10_.sprite;
	_tmp12_ = _tmp11_.height;
	h = _tmp12_;
	_tmp13_ = *entity;
	_tmp14_ = _tmp13_.sprite;
	_tmp15_ = _tmp14_.width;
	w = _tmp15_;
	_tmp16_ = self->renderer;
	_tmp17_ = *entity;
	_tmp18_ = _tmp17_.sprite;
	_tmp19_ = _tmp18_.texture;
	_tmp20_.x = ((gint) x) - (h / 2);
	_tmp20_.y = ((gint) y) - (w / 2);
	_tmp20_.w = (guint) h;
	_tmp20_.h = (guint) w;
	SDL_RenderCopy (_tmp16_, _tmp19_, NULL, &_tmp20_);
}


void game_draw_text (Game* self, Entity* entity, gint tick) {
	Entity _tmp0_ = {0};
	Timer* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	Entity _tmp19_ = {0};
	Timer* _tmp20_ = NULL;
	gint _tmp21_ = 0;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entity != NULL);
	_tmp0_ = *entity;
	_tmp1_ = _tmp0_.expires;
	_tmp2_ = (*_tmp1_).begin;
	if (_tmp2_ >= 0) {
		gint _tmp3_ = 0;
		Entity _tmp4_ = {0};
		Timer* _tmp5_ = NULL;
		gint _tmp6_ = 0;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		_tmp3_ = tick;
		_tmp4_ = *entity;
		_tmp5_ = _tmp4_.expires;
		_tmp6_ = (*_tmp5_).begin;
		_tmp7_ = formatTime (_tmp3_ - _tmp6_);
		_tmp8_ = _tmp7_;
		game_render_text (self, _tmp8_, 50, 100, WHITE);
		_g_free0 (_tmp8_);
	} else {
		Entity _tmp9_ = {0};
		Timer* _tmp10_ = NULL;
		gint _tmp11_ = 0;
		_tmp9_ = *entity;
		_tmp10_ = _tmp9_.expires;
		_tmp11_ = (*_tmp10_).finish;
		if (_tmp11_ >= 0) {
			Entity _tmp12_ = {0};
			Timer* _tmp13_ = NULL;
			gint _tmp14_ = 0;
			gchar* _tmp15_ = NULL;
			gchar* _tmp16_ = NULL;
			gchar* _tmp17_ = NULL;
			gchar* _tmp18_ = NULL;
			_tmp12_ = *entity;
			_tmp13_ = _tmp12_.expires;
			_tmp14_ = (*_tmp13_).finish;
			_tmp15_ = formatTime (_tmp14_);
			_tmp16_ = _tmp15_;
			_tmp17_ = g_strconcat ("Finished in: ", _tmp16_, NULL);
			_tmp18_ = _tmp17_;
			game_render_text (self, _tmp18_, 50, 100, WHITE);
			_g_free0 (_tmp18_);
			_g_free0 (_tmp16_);
		}
	}
	_tmp19_ = *entity;
	_tmp20_ = _tmp19_.expires;
	_tmp21_ = (*_tmp20_).best;
	if (_tmp21_ >= 0) {
		Entity _tmp22_ = {0};
		Timer* _tmp23_ = NULL;
		gint _tmp24_ = 0;
		gchar* _tmp25_ = NULL;
		gchar* _tmp26_ = NULL;
		gchar* _tmp27_ = NULL;
		gchar* _tmp28_ = NULL;
		_tmp22_ = *entity;
		_tmp23_ = _tmp22_.expires;
		_tmp24_ = (*_tmp23_).best;
		_tmp25_ = formatTime (_tmp24_);
		_tmp26_ = _tmp25_;
		_tmp27_ = g_strconcat ("Best time: ", _tmp26_, NULL);
		_tmp28_ = _tmp27_;
		game_render_text (self, _tmp28_, 50, 150, WHITE);
		_g_free0 (_tmp28_);
		_g_free0 (_tmp26_);
	}
}


void game_render (Game* self, gint tick) {
	SDL_Renderer* _tmp0_ = NULL;
	SDL_Renderer* _tmp1_ = NULL;
	Entity* _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	Map* _tmp5_ = NULL;
	SDL_Renderer* _tmp6_ = NULL;
	Vector2d _tmp7_ = {0};
	Entity* _tmp8_ = NULL;
	gint _tmp8__length1 = 0;
	Entity _tmp9_ = {0};
	gint _tmp10_ = 0;
	SDL_Renderer* _tmp11_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->renderer;
	SDL_SetRenderDrawColor (_tmp0_, (guint8) 110, (guint8) 132, (guint8) 174, (guint8) 255);
	_tmp1_ = self->renderer;
	SDL_RenderClear (_tmp1_);
	_tmp2_ = self->entities;
	_tmp2__length1 = self->entities_length1;
	{
		Entity* entity_collection = NULL;
		gint entity_collection_length1 = 0;
		gint _entity_collection_size_ = 0;
		gint entity_it = 0;
		entity_collection = _tmp2_;
		entity_collection_length1 = _tmp2__length1;
		for (entity_it = 0; entity_it < _tmp2__length1; entity_it = entity_it + 1) {
			Entity _tmp3_ = {0};
			Entity entity = {0};
			entity_copy (&entity_collection[entity_it], &_tmp3_);
			entity = _tmp3_;
			{
				Entity _tmp4_ = {0};
				_tmp4_ = entity;
				game_draw (self, &_tmp4_);
				entity_destroy (&entity);
			}
		}
	}
	_tmp5_ = self->map;
	_tmp6_ = self->renderer;
	_tmp7_ = self->camera;
	map_render (_tmp5_, _tmp6_, &_tmp7_);
	_tmp8_ = self->entities;
	_tmp8__length1 = self->entities_length1;
	_tmp9_ = _tmp8_[0];
	_tmp10_ = tick;
	game_draw_text (self, &_tmp9_, _tmp10_);
	_tmp11_ = self->renderer;
	SDL_RenderPresent (_tmp11_);
}


void game_render_text (Game* self, const gchar* text, gint x, gint y, SDL_Color foreColor) {
	SDL_Color outlineColor = {0};
	SDL_Color _tmp0_ = {0};
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = color ((guint8) 0, (guint8) 0, (guint8) 0, (guint8) 64);
	outlineColor = _tmp0_;
	{
		SDL_Renderer* _tmp1_ = NULL;
		TTF_Font* _tmp2_ = NULL;
		const gchar* _tmp3_ = NULL;
		gint _tmp4_ = 0;
		gint _tmp5_ = 0;
		SDL_Renderer* _tmp6_ = NULL;
		TTF_Font* _tmp7_ = NULL;
		const gchar* _tmp8_ = NULL;
		gint _tmp9_ = 0;
		gint _tmp10_ = 0;
		SDL_Color _tmp11_ = {0};
		_tmp1_ = self->renderer;
		_tmp2_ = self->font;
		_tmp3_ = text;
		_tmp4_ = x;
		_tmp5_ = y;
		renderText (_tmp1_, _tmp2_, _tmp3_, _tmp4_, _tmp5_, (int) 2, outlineColor);
		_tmp6_ = self->renderer;
		_tmp7_ = self->font;
		_tmp8_ = text;
		_tmp9_ = x;
		_tmp10_ = y;
		_tmp11_ = foreColor;
		renderText (_tmp6_, _tmp7_, _tmp8_, _tmp9_, _tmp10_, (int) 0, _tmp11_);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp12_ = NULL;
		const gchar* _tmp13_ = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp12_ = e;
		_tmp13_ = _tmp12_->message;
		g_print ("%s\n", _tmp13_);
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void game_update (Game* self, gint tick) {
	Systems* _tmp0_ = NULL;
	Entity* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	gint _tmp2_ = 0;
	Systems* _tmp3_ = NULL;
	Entity* _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	gint _tmp5_ = 0;
	Systems* _tmp6_ = NULL;
	Entity* _tmp7_ = NULL;
	gint _tmp7__length1 = 0;
	gint _tmp8_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->system;
	_tmp1_ = self->entities;
	_tmp1__length1 = self->entities_length1;
	_tmp2_ = tick;
	systems_physics (_tmp0_, &_tmp1_[0], _tmp2_);
	_tmp3_ = self->system;
	_tmp4_ = self->entities;
	_tmp4__length1 = self->entities_length1;
	_tmp5_ = tick;
	systems_camera (_tmp3_, &_tmp4_[0], _tmp5_);
	_tmp6_ = self->system;
	_tmp7_ = self->entities;
	_tmp7__length1 = self->entities_length1;
	_tmp8_ = tick;
	systems_logic (_tmp6_, &_tmp7_[0], _tmp8_);
}


Input game_toInput (Game* self, SDL_Scancode key) {
	Input result = 0;
	SDL_Scancode _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = key;
	switch (_tmp0_) {
		case SDL_SCANCODE_LEFT:
		{
			{
				result = INPUT_left;
				return result;
			}
			break;
		}
		case SDL_SCANCODE_RIGHT:
		{
			{
				result = INPUT_right;
				return result;
			}
			break;
		}
		case SDL_SCANCODE_UP:
		{
			{
				result = INPUT_jump;
				return result;
			}
			break;
		}
		case SDL_SCANCODE_SPACE:
		{
			{
				result = INPUT_jump;
				return result;
			}
			break;
		}
		case SDL_SCANCODE_R:
		{
			{
				result = INPUT_restart;
				return result;
			}
			break;
		}
		case SDL_SCANCODE_Q:
		{
			{
				result = INPUT_quit;
				return result;
			}
			break;
		}
		default:
		break;
	}
	result = INPUT_none;
	return result;
}


void game_handleInput (Game* self) {
	SDL_Event evt = {0};
	g_return_if_fail (self != NULL);
	while (TRUE) {
		SDL_Event _tmp0_ = {0};
		gint _tmp1_ = 0;
		SDL_Event _tmp2_ = {0};
		SDL_EventType _tmp3_ = 0;
		_tmp1_ = SDL_PollEvent (&_tmp0_);
		 (evt);
		evt = _tmp0_;
		if (!(_tmp1_ != 0)) {
			break;
		}
		_tmp2_ = evt;
		_tmp3_ = _tmp2_.type;
		switch (_tmp3_) {
			case SDL_QUIT:
			{
				{
					gboolean* _tmp4_ = NULL;
					gint _tmp4__length1 = 0;
					gboolean _tmp5_ = FALSE;
					_tmp4_ = self->inputs;
					_tmp4__length1 = self->inputs_length1;
					_tmp4_[INPUT_quit] = TRUE;
					_tmp5_ = _tmp4_[INPUT_quit];
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				{
					gboolean* _tmp6_ = NULL;
					gint _tmp6__length1 = 0;
					SDL_Event _tmp7_ = {0};
					SDL_KeyboardEvent _tmp8_ = {0};
					SDL_Keysym _tmp9_ = {0};
					SDL_Scancode _tmp10_ = 0;
					Input _tmp11_ = 0;
					gboolean _tmp12_ = FALSE;
					_tmp6_ = self->inputs;
					_tmp6__length1 = self->inputs_length1;
					_tmp7_ = evt;
					_tmp8_ = _tmp7_.key;
					_tmp9_ = _tmp8_.keysym;
					_tmp10_ = _tmp9_.scancode;
					_tmp11_ = game_toInput (self, _tmp10_);
					_tmp6_[_tmp11_] = TRUE;
					_tmp12_ = _tmp6_[_tmp11_];
				}
				break;
			}
			case SDL_KEYUP:
			{
				{
					gboolean* _tmp13_ = NULL;
					gint _tmp13__length1 = 0;
					SDL_Event _tmp14_ = {0};
					SDL_KeyboardEvent _tmp15_ = {0};
					SDL_Keysym _tmp16_ = {0};
					SDL_Scancode _tmp17_ = 0;
					Input _tmp18_ = 0;
					gboolean _tmp19_ = FALSE;
					_tmp13_ = self->inputs;
					_tmp13__length1 = self->inputs_length1;
					_tmp14_ = evt;
					_tmp15_ = _tmp14_.key;
					_tmp16_ = _tmp15_.keysym;
					_tmp17_ = _tmp16_.scancode;
					_tmp18_ = game_toInput (self, _tmp17_);
					_tmp13_[_tmp18_] = FALSE;
					_tmp19_ = _tmp13_[_tmp18_];
				}
				break;
			}
			default:
			break;
		}
	}
	 (evt);
}


static void game_instance_init (Game * self) {
	self->retainCount__ = 1;
}


void game_free (Game* self) {
	self->inputs = (g_free (self->inputs), NULL);
	_TTF_CloseFont0 (self->font);
	_SDL_FreeRW0 (self->font_rw);
	 (self->evt);
	_map_release0 (self->map);
	_SDL_FreeSurface0 (self->playerSurface);
	_SDL_DestroyTexture0 (self->playerTexture);
	_SDL_DestroyTexture0 (self->grassTexture);
	_systems_release0 (self->system);
	self->entities = (_vala_Entity_array_free (self->entities, self->entities_length1), NULL);
	g_slice_free (Game, self);
}


