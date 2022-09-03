#pragma once
#include "nsmb.h"


enum class SpawnItem : u32
{
	MushroomFlower,
	Star,
	Coin,
	Poof,
	MultiCoin,
	MegaMushroom,
	Unused0,
	OneUp,
	MultiCoinMushroom,
	Flower,
	Vine,
	BlueShell,
	Unused1,
	Springboard,
	Unused2,
	None,
	AreaController,
	Empty,
	EntranceVine,
	Coin3,
	Coin4,
	Unused3,
	Unused4,
	Unused5,
	Unused6,
	MiniMushroom,
	FlyingCoins,
	ConditionalStar,
	Unused7,
	ThrownCoin,
	Boo,
	TNone,
};


enum class ItemType : u16
{
	Mushroom,
	Fireflower,
	Star,
	Coin,
	MegaMushroom,
	GlitchedShell,
	OneUp,
	Vine,
	Blueshell,
	Unused0,
	GlitchedVine,
	Unused1,
	LightningBolt,
	MiniMushroom,
	OneUpCard,
	ThreeUpCard,
	DoubleCard,
	BowserCard,
	MushroomCard,
	FireflowerCard,
	BlueshellCard,
	MiniMushroomCard,
	MegaMushroomCard
};


enum class ItemSpawnBehaviour : u32
{
	ItemOut,
	SmallBounce,
	Triggerable,
	EnemyDrop,
	BigBounce,
	UpDownDash,
	FallingStairs
};


class Toadsworth;


class Item : public StageEntity
{
public:

	typedef bool(Item::*StateFunction)();

	//020d475c
	bool checkConsume();                // returns true if the item has been consumed by a player, false otherwise

	//020d4664
	void checkValidTile();              // Checks whether the item resides in a valid tile and destroys it if not

	//020d4eb8
	bool switchState(StateFunction function);    //Switches the state function to function. Always returns true.

	bool onPrepareResources();

	static constexpr u16 objectID = 31;

	static constexpr u16 updatePriority = objectID;
	static constexpr u16 renderPriority = 44;

	Toadsworth* toadsworth;			    // A pointer to your local toadsworth
	ModelAnm itemModel;			        // Model of the item (mega mushroom only)
	Model blockModel;			        // Model of the activating block
	PointSensor dropSensor;			    // Point sensor used to detect when the dropped item hits the ground
	StateFunction updateFunction;		// Current update function
	Player* collidedPlayer;			    // Pointer to the player it collided against, if any
	Vec3 blockScale;			        // Scale of the render block
	Vec2 blockPosition;			        // Position of the render block OR growing vine end position
	fx32 endPositionX;			        // End position X (green card only)
	fx32 endPositionY;			        // End position Y
	u32 unk56C;			                // Set to 0 when the red card is about to rotate to the bottom screen
	fx32 fixedDropXOffset;			    // If in fixed drop offset mode, causes the item to maintain the given offset to the player
	SpawnItem spawnItem;			    // Spawn item, used to set up the correct state for the real item. Different for level/toadhouse.
	u32 playerID;			            // Player actor who triggered the spawner
	ItemSpawnBehaviour spawnBehaviour;	// Item spawn behaviour
	u32 blockHitMode;			        // 0/1: Side, 2: Upwards, 3: Downwards
	u32 enemyDropDown;			        // 0x200 if enemy drop should drop down only
	u32 fastDrop;			            // 0x400 if fast drop is enabled
	u32 fixedDropXFlag;			        // If 1, causes the dropping item to have a fixed relative X to the player
	u32 renderOnTopFlag;			    // If 1, causes the item to render in front of tiles when spawning
	u32 specialEnemyDrop;			    // If 1, enforces enemy drop behaviour (bounce has NO initial X velocity)
	u16 fireflowerAnimTimer;		    // When expired, starts a fireflower animation cycle
	u16 fireflowerAnimTick;			    // Animation tick: 1 start, 8 end, 0 waiting for timer
	fx16 redCardRotation;			    // Rotation of red item cards
	u16 dropMegaSharedState;			// Shared state between drops and megamushroom. 0: spawn, 1: drop/delay, 2: active
	ItemType item;			            // Real item type
	u16 timer;			                // Generic timer, used for cards, coins and fireflowers
	u16 blockOutMode;			        // Mega/Trigger: 3: Freezes items until ground touch (movementState = 1)
	u16 dropReleaseTimer;			    // When expired, drops the item
	u16 dropAnimTick;			        // 0: start, 1: end (pending drop animation)
	u16 bigBounceTimer;			        // When expired, big bounce becomes inactive, e.g. mushrooms/fireflowers execute their normal behaviour
	u16 bigBounceActive;			    // 1 if it's performing a big bounce, 0 otherwise
	u16 spawnDelayTimer;			    // When expired, enables actor collisions (timer-based spawn behaviour only)
	u16 blueshellParticleTimer;			// When expired, blue shell particles are spawned (4 ticks)
	u16 mpDespawnTimer;			        // When expired, the item despawns (MP only)
	u16 mpVisibilityTimer;			    // When expired, the item's visibility is toggled (MP only)
	u16 mpHideItem;			            // If 1, hides the item (MP only)
	bool freeVine;			            // True if the vine is growing freely, e.g. terminates after 8 blocks and floats.
	u8 bowserCardScaleState;			// 0: Enlarge, 1: Shrink
	u8 threeUpCardSpawns;			    // Number of already spawned 1-ups from the 3-up card (note that if 2, the last one is converted from the current item instead of getting spawned)
	bool doubleCardApplied;			    // True if the double card effect got applied or is not applicable anymore
	u8 redCardAffineSet;			    // Affine set of the red card
	u8 cardBlockID;			            // Corresponding block ID of card
	u8 cardItemState;			        // Substate for cards
	bool activatingBlockCollision;		// True if (in this frame) the item just collided with an activating block
	bool spawning;			            // True if the item is spawning, e.g. doesn't perform its individual animations/logic yet
	u8 dropState;			            // Item drop state (0-3)
	u8 dynamicMovementState;			// Star, mushroom, mega: 0: Move on spawn, 1: Immovable until drop, 2: Movable after drop
	u8 mushroomAnimTick;			    // 0 start, 3 end
	u8 starPaletteTick;			        // 0-1, sets the star's palette index
	u8 starAnimTimer;			        // Controls the animation tick of stars
	u8 vineCoinAnimTick;			    // 0-3 (Vine/Coin only)
	u8 vineCoinMegaAnimTimer;			// Controls the animation tick of vines/coins and the pause after mega mushroom spawn animation
	bool renderBlock;			        // True if it should render an animated block
	u8 spriteRenderPriority;			// Render priority of the item (sprites)
	bool triggered;			            // (Triggered only) True to trigger item updates
	u8 blockTexPaletteID;			    // ID of the 3D block's texture palette
	s8 collidedPlayerID;			    // ID of the player it collided against, if any
	s8 updateStep;			            // 0:init, 1:update
	u8 cardID;			                // ID of the red toadhouse card
	u8 unused5CF;			            // Unused (& 0x100), MP, vine, drop from top only

};
NTR_SIZE_GUARD(Item, 0x5D0);
