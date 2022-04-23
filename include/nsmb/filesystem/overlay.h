#pragma once
#include "file.h"


namespace FS
{
	/**
	 * \brief The %Overlay namespace.
	 *
	 * This namespace contains the functions that allow
	 * code to overlap in certain regions of memory.
	 * */
	namespace Overlay {

		/// \brief The structure that contains the information of an overlay.
		struct Entry {

			u32 id;
			u32 start;
			u32 size;
			u32 refCount;

		};

		// 0x02085D0C
		/// \brief The table that contains the information about the loaded overlays.
		extern Entry loadedOverlays[16];

		// 0x02009484
		/**
		 * \brief Prepares the loaded overlay table.
		 * */
		void initLoadedOverlayTable();

		// 0x020094B8
		/**
		 * \brief Removes an overlay from the loaded overlay table.
		 *
		 * \param overlayID The identifier of the overlay to remove.
		 * */
		void untrack(u32 overlayID);

		// 0x02009510
		/**
		 * \brief Loads an overlay.
		 *
		 * \param overlayID The identifier of the overlay to load.
		 * */
		void load(u32 overlayID);

		// 0x02009560
		/**
		 * \brief Loads and adds an overlay to the loaded overlay table.
		 *
		 * \param overlayID The identifier of the overlay to load and track.
		 * */
		bool trackAndLoad(u32 overlayID);

		// 0x02009798
		/**
		 * \brief Invalidates the memory region of an overlay.
		 *
		 * \param info The pointer to the overlay info structure.
		 * */
		void flush(FSOverlayInfo* info);

	}
}
