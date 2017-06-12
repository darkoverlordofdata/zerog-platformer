/* Game.c generated by valac 0.34.8, the Vala compiler
 * generated from Game.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_pixels.h>
#include <chipmunk/chipmunk.h>


#define TYPE_POINT2D (point2d_get_type ())
typedef struct _Point2d Point2d;
typedef struct _Game Game;
typedef struct _Map Map;
typedef struct _sdxgraphicsCamera sdxgraphicsCamera;
typedef sdxgraphicsCamera sdxgraphicsCameraInnerCamera;
typedef struct _Entities Entities;
typedef struct _Hud Hud;

#define TYPE_ENTITY (entity_get_type ())

#define TYPE_CATEGORY (category_get_type ())

#define TYPE_ACTOR (actor_get_type ())
typedef struct _sdxgraphicsSprite sdxgraphicsSprite;

#define TYPE_VECTOR2D (vector2d_get_type ())
typedef struct _Vector2d Vector2d;

#define TYPE_TIMER (timer_get_type ())
typedef struct _Timer Timer;

#define TYPE_HEALTH (health_get_type ())
typedef struct _Health Health;
typedef struct _Entity Entity;
typedef struct _systemsSystem systemsSystem;
void map_release (Map* self);
void map_free (Map* self);
Map* map_retain (Map* self);
#define _map_release0(var) ((var == NULL) ? NULL : (var = (map_release (var), NULL)))
void sdx_graphics_camera_release (sdxgraphicsCamera* self);
void sdx_graphics_camera_free (sdxgraphicsCamera* self);
sdxgraphicsCamera* sdx_graphics_camera_retain (sdxgraphicsCamera* self);
#define _sdx_graphics_camera_release0(var) ((var == NULL) ? NULL : (var = (sdx_graphics_camera_release (var), NULL)))
void entities_release (Entities* self);
void entities_free (Entities* self);
Entities* entities_retain (Entities* self);
#define _entities_release0(var) ((var == NULL) ? NULL : (var = (entities_release (var), NULL)))
void hud_release (Hud* self);
void hud_free (Hud* self);
Hud* hud_retain (Hud* self);
#define _hud_release0(var) ((var == NULL) ? NULL : (var = (hud_release (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
#define _cpSpaceFree0(var) ((var == NULL) ? NULL : (var = (cpSpaceFree (var), NULL)))
#define _cpBodyFree0(var) ((var == NULL) ? NULL : (var = (cpBodyFree (var), NULL)))
#define _cpShapeFree0(var) ((var == NULL) ? NULL : (var = (cpShapeFree (var), NULL)))
typedef systemsSystem systemsLogicSystem;
typedef systemsSystem systemsPhysicsSystem;

#define SDX_GRAPHICS_CAMERA_TYPE_KIND (sdx_graphics_camera_kind_get_type ())
void systems_system_release (systemsSystem* self);
void systems_system_free (systemsSystem* self);
systemsSystem* systems_system_retain (systemsSystem* self);
#define _systems_system_release0(var) ((var == NULL) ? NULL : (var = (systems_system_release (var), NULL)))

#define SDX_TYPE_DIRECTION (sdx_direction_get_type ())

struct _Point2d {
	gdouble x;
	gdouble y;
};

typedef enum  {
	CATEGORY_BACKGROUND,
	CATEGORY_PLAYER,
	CATEGORY_BONUS
} Category;

typedef enum  {
	ACTOR_DEFAULT,
	ACTOR_BACKGROUND,
	ACTOR_TEXT,
	ACTOR_PLAYER,
	ACTOR_BONUS,
	ACTOR_HUD
} Actor;

struct _Vector2d {
	gdouble x;
	gdouble y;
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
	sdxgraphicsSprite* sprite;
	Vector2d* size;
	Vector2d* scale;
	SDL_Color* tint;
	Timer* expires;
	Health* health;
	Vector2d* velocity;
};

struct _Game {
	gint retainCount__;
	Map* map;
	sdxgraphicsCameraInnerCamera* camera;
	Entities* factory;
	Hud* hud;
	Entity* player;
	gboolean touch;
	GList* sprites;
	Entity* pool;
	gint pool_length1;
	systemsSystem** sys;
	gint sys_length1;
	cpSpace* space;
	cpBody* body;
	cpCircleShape* shape;
	cpBody* groundBody;
	cpSegmentShape* groundShape;
};

typedef enum  {
	SDX_GRAPHICS_CAMERA_KIND_FluidCamera,
	SDX_GRAPHICS_CAMERA_KIND_InnerCamera,
	SDX_GRAPHICS_CAMERA_KIND_SimpleCamera
} sdxgraphicsCameraKind;

typedef void (*sdxgraphicsCameraCameraSetPosition) (Point2d* position, void* user_data);
struct _sdxgraphicsCamera {
	gint _retainCount;
	sdxgraphicsCameraKind kind;
	Vector2d position;
	sdxgraphicsCameraCameraSetPosition setPosition;
	gpointer setPosition_target;
	GDestroyNotify setPosition_target_destroy_notify;
};

typedef void (*systemsSystemInitialize) (void* user_data);
typedef void (*systemsSystemExecute) (Entity** player, gint tick, void* user_data);
struct _systemsSystem {
	gint _retainCount;
	systemsSystemInitialize initialize;
	gpointer initialize_target;
	GDestroyNotify initialize_target_destroy_notify;
	systemsSystemExecute execute;
	gpointer execute_target;
	GDestroyNotify execute_target_destroy_notify;
};

typedef enum  {
	SDX_DIRECTION_NONE,
	SDX_DIRECTION_LEFT,
	SDX_DIRECTION_RIGHT,
	SDX_DIRECTION_UP,
	SDX_DIRECTION_DOWN
} sdxDirection;


extern SDL_Color sdx_bgdColor;
extern gint sdx_height;
extern gint sdx_width;
extern gboolean* sdx_direction;
extern gint sdx_direction_length1;
extern gboolean sdx_mouseDown;
extern gdouble sdx_mouseY;
extern gdouble sdx_mouseX;

GType point2d_get_type (void) G_GNUC_CONST;
Point2d* point2d_dup (const Point2d* self);
void point2d_free (Point2d* self);
void game_free (Game* self);
void map_free (Map* self);
void sdx_graphics_camera_free (sdxgraphicsCamera* self);
void entities_free (Entities* self);
void hud_free (Hud* self);
GType entity_get_type (void) G_GNUC_CONST;
GType category_get_type (void) G_GNUC_CONST;
GType actor_get_type (void) G_GNUC_CONST;
void sdx_graphics_sprite_free (sdxgraphicsSprite* self);
GType vector2d_get_type (void) G_GNUC_CONST;
Vector2d* vector2d_dup (const Vector2d* self);
void vector2d_free (Vector2d* self);
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
void systems_system_free (systemsSystem* self);
static void game_instance_init (Game * self);
static void _vala_Entity_array_free (Entity* array, gint array_length);
Game* game_retain (Game* self);
void game_release (Game* self);
void game_free (Game* self);
Game* game_new (void);
void sdx_setResourceBase (const gchar* path);
void sdx_setDefaultFont (const gchar* path, gint size);
sdxgraphicsCameraInnerCamera* sdx_graphics_camera_inner_camera_new (gdouble x, gdouble y);
Entities* entities_new (void);
Map* map_new (const gchar* mapPath);
void entities_createBerry (Entities* self, Entity* result);
void entities_createPlayer (Entities* self, Entity* result);
systemsLogicSystem* systems_logic_system_new (Game* game);
systemsPhysicsSystem* systems_physics_system_new (Game* game);
Hud* hud_new (void);
void game_update (Game* self, gint tick);
void game_mapInput (Game* self);
void sdx_update (void);
GType sdx_graphics_camera_kind_get_type (void) G_GNUC_CONST;
void game_render (Game* self, gint tick);
void sdx_begin (void);
void map_render (Map* self, sdxgraphicsCamera* camera);
void point2d_sub (Point2d *self, Vector2d* v, Point2d* result);
void sdx_graphics_sprite_render (sdxgraphicsSprite* self, gint x, gint y, SDL_Rect* clip);
void hud_render (Hud* self, Entity** player, gint tick);
void sdx_end (void);
GType sdx_direction_get_type (void) G_GNUC_CONST;
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);

const Point2d WINDOW_SIZE = {(gdouble) 1280, (gdouble) 720};
extern const SDL_Color SDX_COLOR_LiteSlateBlue;

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


Game* game_new (void) {
	Game* self;
	sdxgraphicsCameraInnerCamera* _tmp0_ = NULL;
	Entities* _tmp1_ = NULL;
	Map* _tmp2_ = NULL;
	Entities* _tmp3_ = NULL;
	Entity _tmp4_ = {0};
	Entities* _tmp5_ = NULL;
	Entity _tmp6_ = {0};
	Entity* _tmp7_ = NULL;
	systemsLogicSystem* _tmp8_ = NULL;
	systemsPhysicsSystem* _tmp9_ = NULL;
	systemsSystem** _tmp10_ = NULL;
	Hud* _tmp11_ = NULL;
	Entity* _tmp12_ = NULL;
	gint _tmp12__length1 = 0;
	cpSpace* _tmp18_ = NULL;
	cpSpace* _tmp19_ = NULL;
	cpVect _tmp20_ = {0};
	cpBody* _tmp21_ = NULL;
	cpBody* _tmp22_ = NULL;
	Entity* _tmp23_ = NULL;
	Point2d _tmp24_ = {0};
	gdouble _tmp25_ = 0.0;
	Entity* _tmp26_ = NULL;
	Point2d _tmp27_ = {0};
	gdouble _tmp28_ = 0.0;
	cpVect _tmp29_ = {0};
	cpSpace* _tmp30_ = NULL;
	cpBody* _tmp31_ = NULL;
	cpBody* _tmp32_ = NULL;
	cpVect _tmp33_ = {0};
	cpCircleShape* _tmp34_ = NULL;
	cpCircleShape* _tmp35_ = NULL;
	cpCircleShape* _tmp36_ = NULL;
	cpCircleShape* _tmp37_ = NULL;
	Entity* _tmp38_ = NULL;
	cpCircleShape* _tmp39_ = NULL;
	cpSpace* _tmp40_ = NULL;
	cpCircleShape* _tmp41_ = NULL;
	cpBody* _tmp42_ = NULL;
	cpBody* _tmp43_ = NULL;
	gint _tmp44_ = 0;
	cpVect _tmp45_ = {0};
	gint _tmp46_ = 0;
	gint _tmp47_ = 0;
	cpVect _tmp48_ = {0};
	cpSegmentShape* _tmp49_ = NULL;
	cpSegmentShape* _tmp50_ = NULL;
	cpSegmentShape* _tmp51_ = NULL;
	cpSpace* _tmp52_ = NULL;
	cpSegmentShape* _tmp53_ = NULL;
	self = g_slice_new0 (Game);
	game_instance_init (self);
	sdx_setResourceBase ("/darkoverlordofdata/platformer");
	sdx_setDefaultFont ("assets/OpenDyslexic-Bold.otf", 28);
	_tmp0_ = sdx_graphics_camera_inner_camera_new ((gdouble) 0, (gdouble) 0);
	_sdx_graphics_camera_release0 (self->camera);
	self->camera = _tmp0_;
	sdx_bgdColor = SDX_COLOR_LiteSlateBlue;
	_tmp1_ = entities_new ();
	_entities_release0 (self->factory);
	self->factory = _tmp1_;
	_tmp2_ = map_new ("assets/default.json");
	_map_release0 (self->map);
	self->map = _tmp2_;
	_tmp3_ = self->factory;
	entities_createBerry (_tmp3_, &_tmp4_);
	_tmp5_ = self->factory;
	entities_createPlayer (_tmp5_, &_tmp6_);
	_tmp7_ = g_new0 (Entity, 2);
	_tmp7_[0] = _tmp4_;
	_tmp7_[1] = _tmp6_;
	self->pool = (_vala_Entity_array_free (self->pool, self->pool_length1), NULL);
	self->pool = _tmp7_;
	self->pool_length1 = 2;
	_tmp8_ = systems_logic_system_new (self);
	_tmp9_ = systems_physics_system_new (self);
	_tmp10_ = g_new0 (systemsSystem*, 2 + 1);
	_tmp10_[0] = (systemsSystem*) _tmp8_;
	_tmp10_[1] = (systemsSystem*) _tmp9_;
	self->sys = (_vala_array_free (self->sys, self->sys_length1, (GDestroyNotify) systems_system_release), NULL);
	self->sys = _tmp10_;
	self->sys_length1 = 2;
	_tmp11_ = hud_new ();
	_hud_release0 (self->hud);
	self->hud = _tmp11_;
	_tmp12_ = self->pool;
	_tmp12__length1 = self->pool_length1;
	self->player = &_tmp12_[1];
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp13_ = FALSE;
			_tmp13_ = TRUE;
			while (TRUE) {
				Entity* _tmp15_ = NULL;
				gint _tmp15__length1 = 0;
				Entity* _tmp16_ = NULL;
				gint _tmp16__length1 = 0;
				gint _tmp17_ = 0;
				if (!_tmp13_) {
					gint _tmp14_ = 0;
					_tmp14_ = i;
					i = _tmp14_ + 1;
				}
				_tmp13_ = FALSE;
				_tmp15_ = self->pool;
				_tmp15__length1 = self->pool_length1;
				if (!(i <= (_tmp15__length1 - 1))) {
					break;
				}
				_tmp16_ = self->pool;
				_tmp16__length1 = self->pool_length1;
				_tmp17_ = i;
				self->sprites = g_list_append (self->sprites, &_tmp16_[_tmp17_]);
			}
		}
	}
	_tmp18_ = cpSpaceNew ();
	_cpSpaceFree0 (self->space);
	self->space = _tmp18_;
	_tmp19_ = self->space;
	_tmp20_.x = (gdouble) 0;
	_tmp20_.y = (gdouble) 100;
	cpSpaceSetGravity (_tmp19_, _tmp20_);
	_tmp21_ = cpBodyNew ((gdouble) 100, INFINITY);
	_cpBodyFree0 (self->body);
	self->body = _tmp21_;
	_tmp22_ = self->body;
	_tmp23_ = self->player;
	_tmp24_ = (*_tmp23_).position;
	_tmp25_ = _tmp24_.x;
	_tmp26_ = self->player;
	_tmp27_ = (*_tmp26_).position;
	_tmp28_ = _tmp27_.y;
	_tmp29_.x = _tmp25_;
	_tmp29_.y = _tmp28_;
	cpBodySetPosition (_tmp22_, _tmp29_);
	_tmp30_ = self->space;
	_tmp31_ = self->body;
	cpSpaceAddBody (_tmp30_, _tmp31_);
	_tmp32_ = self->body;
	_tmp33_.x = (gdouble) 0;
	_tmp33_.y = (gdouble) 0;
	_tmp34_ = cpCircleShapeNew (_tmp32_, (gdouble) 20, _tmp33_);
	_cpShapeFree0 (self->shape);
	self->shape = _tmp34_;
	_tmp35_ = self->shape;
	cpShapeSetElasticity ((cpShape*) _tmp35_, 0.5);
	_tmp36_ = self->shape;
	cpShapeSetFriction ((cpShape*) _tmp36_, 0.8);
	_tmp37_ = self->shape;
	_tmp38_ = self->player;
	cpShapeSetUserData ((cpShape*) _tmp37_, _tmp38_);
	_tmp39_ = self->shape;
	cpShapeSetCollisionType ((cpShape*) _tmp39_, 1);
	_tmp40_ = self->space;
	_tmp41_ = self->shape;
	cpSpaceAddShape (_tmp40_, (cpShape*) _tmp41_);
	_tmp42_ = cpBodyNewStatic ();
	self->groundBody = _tmp42_;
	_tmp43_ = self->groundBody;
	_tmp44_ = sdx_height;
	_tmp45_.x = (gdouble) 0;
	_tmp45_.y = (gdouble) (_tmp44_ - 150);
	_tmp46_ = sdx_width;
	_tmp47_ = sdx_height;
	_tmp48_.x = (gdouble) _tmp46_;
	_tmp48_.y = (gdouble) (_tmp47_ - 150);
	_tmp49_ = cpSegmentShapeNew (_tmp43_, _tmp45_, _tmp48_, (gdouble) 10);
	_cpShapeFree0 (self->groundShape);
	self->groundShape = _tmp49_;
	_tmp50_ = self->groundShape;
	cpShapeSetElasticity ((cpShape*) _tmp50_, 0.5);
	_tmp51_ = self->groundShape;
	cpShapeSetFriction ((cpShape*) _tmp51_, 1.0);
	_tmp52_ = self->space;
	_tmp53_ = self->groundShape;
	cpSpaceAddShape (_tmp52_, (cpShape*) _tmp53_);
	return self;
}


/**
 * increment the game model
 */
static gpointer _systems_system_retain0 (gpointer self) {
	return self ? systems_system_retain (self) : NULL;
}


void game_update (Game* self, gint tick) {
	cpSpace* _tmp0_ = NULL;
	cpVect pos = {0};
	cpBody* _tmp1_ = NULL;
	cpVect _tmp2_ = {0};
	cpVect _tmp3_ = {0};
	gdouble _tmp4_ = 0.0;
	cpVect _tmp5_ = {0};
	gdouble _tmp6_ = 0.0;
	Point2d _tmp7_ = {0};
	sdxgraphicsCameraInnerCamera* _tmp8_ = NULL;
	sdxgraphicsCameraCameraSetPosition _tmp9_ = NULL;
	void* _tmp9__target = NULL;
	Entity* _tmp10_ = NULL;
	Point2d _tmp11_ = {0};
	systemsSystem** _tmp12_ = NULL;
	gint _tmp12__length1 = 0;
	g_return_if_fail (self != NULL);
	game_mapInput (self);
	_tmp0_ = self->space;
	cpSpaceStep (_tmp0_, 0.1);
	_tmp1_ = self->body;
	_tmp2_ = cpBodyGetPosition (_tmp1_);
	pos = _tmp2_;
	sdx_update ();
	_tmp3_ = pos;
	_tmp4_ = _tmp3_.x;
	_tmp5_ = pos;
	_tmp6_ = _tmp5_.y;
	_tmp7_.x = _tmp4_;
	_tmp7_.y = _tmp6_;
	(*self->player).position = _tmp7_;
	_tmp8_ = self->camera;
	_tmp9_ = ((sdxgraphicsCamera*) _tmp8_)->setPosition;
	_tmp9__target = ((sdxgraphicsCamera*) _tmp8_)->setPosition_target;
	_tmp10_ = self->player;
	_tmp11_ = (*_tmp10_).position;
	_tmp9_ (&_tmp11_, _tmp9__target);
	_tmp12_ = self->sys;
	_tmp12__length1 = self->sys_length1;
	{
		systemsSystem** system_collection = NULL;
		gint system_collection_length1 = 0;
		gint _system_collection_size_ = 0;
		gint system_it = 0;
		system_collection = _tmp12_;
		system_collection_length1 = _tmp12__length1;
		for (system_it = 0; system_it < _tmp12__length1; system_it = system_it + 1) {
			systemsSystem* _tmp13_ = NULL;
			systemsSystem* system = NULL;
			_tmp13_ = _systems_system_retain0 (system_collection[system_it]);
			system = _tmp13_;
			{
				systemsSystem* _tmp14_ = NULL;
				systemsSystemExecute _tmp15_ = NULL;
				void* _tmp15__target = NULL;
				gint _tmp16_ = 0;
				_tmp14_ = system;
				_tmp15_ = _tmp14_->execute;
				_tmp15__target = _tmp14_->execute_target;
				_tmp16_ = tick;
				_tmp15_ (&self->player, _tmp16_, _tmp15__target);
				_systems_system_release0 (system);
			}
		}
	}
}


/**
 * render the background, sprites & foregound
 */
void game_render (Game* self, gint tick) {
	Map* _tmp0_ = NULL;
	sdxgraphicsCameraInnerCamera* _tmp1_ = NULL;
	GList* _tmp2_ = NULL;
	Hud* _tmp12_ = NULL;
	gint _tmp13_ = 0;
	g_return_if_fail (self != NULL);
	sdx_begin ();
	_tmp0_ = self->map;
	_tmp1_ = self->camera;
	map_render (_tmp0_, (sdxgraphicsCamera*) _tmp1_);
	_tmp2_ = self->sprites;
	{
		GList* sprite_collection = NULL;
		GList* sprite_it = NULL;
		sprite_collection = _tmp2_;
		for (sprite_it = sprite_collection; sprite_it != NULL; sprite_it = sprite_it->next) {
			Entity* sprite = NULL;
			sprite = sprite_it->data;
			{
				Point2d position = {0};
				sdxgraphicsCameraInnerCamera* _tmp3_ = NULL;
				Vector2d _tmp4_ = {0};
				Point2d _tmp5_ = {0};
				Entity* _tmp6_ = NULL;
				sdxgraphicsSprite* _tmp7_ = NULL;
				Point2d _tmp8_ = {0};
				gdouble _tmp9_ = 0.0;
				Point2d _tmp10_ = {0};
				gdouble _tmp11_ = 0.0;
				_tmp3_ = self->camera;
				_tmp4_ = ((sdxgraphicsCamera*) _tmp3_)->position;
				point2d_sub (&(*sprite).position, &_tmp4_, &_tmp5_);
				position = _tmp5_;
				_tmp6_ = sprite;
				_tmp7_ = (*_tmp6_).sprite;
				_tmp8_ = position;
				_tmp9_ = _tmp8_.x;
				_tmp10_ = position;
				_tmp11_ = _tmp10_.y;
				sdx_graphics_sprite_render (_tmp7_, (gint) _tmp9_, (gint) _tmp11_, NULL);
			}
		}
	}
	_tmp12_ = self->hud;
	_tmp13_ = tick;
	hud_render (_tmp12_, &self->player, _tmp13_);
	sdx_end ();
}


/**
 *	map touch input for android into left/right/jump
 * 
 * 	 +------------------- // // --------------------+
 * 	 | (0, 0) |                            | (w, 0) |
 * 	 |        |  	        	       	   |        |
 * 	 |   J    |                            |   J    |
 * 	 |        |                            |        |
 * 	 +--------+                            +--------+
 * 	 |        |                            |        |
 * 	 |        |                            |        |
 * 	 |   LJ   |                            |   RJ   |
 * 	 |        |                            |        |
 * 	 +--------+                            +--------+
 * 	 |        |                            |        |
 * 	 |    L   |                            |    R   |
 * 	 |        |                            |        |
 * 	 | (0, h) |                            | (w, h) |
 * 	 +------------------- // // --------------------+
 * 
 */
void game_mapInput (Game* self) {
	gint sz = 0;
	gint _tmp0_ = 0;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp10_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = sdx_height;
	sz = _tmp0_ / 3;
	_tmp1_ = self->touch;
	if (_tmp1_) {
		gboolean* _tmp2_ = NULL;
		gint _tmp2__length1 = 0;
		gboolean _tmp3_ = FALSE;
		gboolean* _tmp4_ = NULL;
		gint _tmp4__length1 = 0;
		gboolean _tmp5_ = FALSE;
		gboolean* _tmp6_ = NULL;
		gint _tmp6__length1 = 0;
		gboolean _tmp7_ = FALSE;
		gboolean* _tmp8_ = NULL;
		gint _tmp8__length1 = 0;
		gboolean _tmp9_ = FALSE;
		_tmp2_ = sdx_direction;
		_tmp2__length1 = sdx_direction_length1;
		_tmp2_[SDX_DIRECTION_LEFT] = FALSE;
		_tmp3_ = _tmp2_[SDX_DIRECTION_LEFT];
		_tmp4_ = sdx_direction;
		_tmp4__length1 = sdx_direction_length1;
		_tmp4_[SDX_DIRECTION_RIGHT] = FALSE;
		_tmp5_ = _tmp4_[SDX_DIRECTION_RIGHT];
		_tmp6_ = sdx_direction;
		_tmp6__length1 = sdx_direction_length1;
		_tmp6_[SDX_DIRECTION_UP] = FALSE;
		_tmp7_ = _tmp6_[SDX_DIRECTION_UP];
		_tmp8_ = sdx_direction;
		_tmp8__length1 = sdx_direction_length1;
		_tmp8_[SDX_DIRECTION_DOWN] = FALSE;
		_tmp9_ = _tmp8_[SDX_DIRECTION_DOWN];
		self->touch = FALSE;
	}
	_tmp10_ = sdx_mouseDown;
	if (_tmp10_) {
		gdouble _tmp11_ = 0.0;
		gint _tmp12_ = 0;
		gdouble _tmp15_ = 0.0;
		gint _tmp16_ = 0;
		self->touch = TRUE;
		_tmp11_ = sdx_mouseY;
		_tmp12_ = sz;
		if (_tmp11_ < ((gdouble) (_tmp12_ * 2))) {
			gboolean* _tmp13_ = NULL;
			gint _tmp13__length1 = 0;
			gboolean _tmp14_ = FALSE;
			_tmp13_ = sdx_direction;
			_tmp13__length1 = sdx_direction_length1;
			_tmp13_[SDX_DIRECTION_UP] = TRUE;
			_tmp14_ = _tmp13_[SDX_DIRECTION_UP];
		}
		_tmp15_ = sdx_mouseX;
		_tmp16_ = sz;
		if (_tmp15_ < ((gdouble) _tmp16_)) {
			gboolean* _tmp17_ = NULL;
			gint _tmp17__length1 = 0;
			gboolean _tmp18_ = FALSE;
			_tmp17_ = sdx_direction;
			_tmp17__length1 = sdx_direction_length1;
			_tmp17_[SDX_DIRECTION_LEFT] = TRUE;
			_tmp18_ = _tmp17_[SDX_DIRECTION_LEFT];
		} else {
			gdouble _tmp19_ = 0.0;
			gint _tmp20_ = 0;
			gint _tmp21_ = 0;
			_tmp19_ = sdx_mouseX;
			_tmp20_ = sdx_width;
			_tmp21_ = sz;
			if (_tmp19_ > ((gdouble) (_tmp20_ - _tmp21_))) {
				gboolean* _tmp22_ = NULL;
				gint _tmp22__length1 = 0;
				gboolean _tmp23_ = FALSE;
				_tmp22_ = sdx_direction;
				_tmp22__length1 = sdx_direction_length1;
				_tmp22_[SDX_DIRECTION_RIGHT] = TRUE;
				_tmp23_ = _tmp22_[SDX_DIRECTION_RIGHT];
			}
		}
	}
}


static void game_instance_init (Game * self) {
	self->retainCount__ = 1;
	self->sprites = NULL;
}


void game_free (Game* self) {
	_map_release0 (self->map);
	_sdx_graphics_camera_release0 (self->camera);
	_entities_release0 (self->factory);
	_hud_release0 (self->hud);
	_g_list_free0 (self->sprites);
	self->pool = (_vala_Entity_array_free (self->pool, self->pool_length1), NULL);
	self->sys = (_vala_array_free (self->sys, self->sys_length1, (GDestroyNotify) systems_system_release), NULL);
	_cpSpaceFree0 (self->space);
	_cpBodyFree0 (self->body);
	_cpShapeFree0 (self->shape);
	_cpShapeFree0 (self->groundShape);
	g_slice_free (Game, self);
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



