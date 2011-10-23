/*
 * Section descriptor functions
 *
 * Copyright (c) 2011, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBEXE_SECTION_DESCRIPTOR_H )
#define _LIBEXE_SECTION_DESCRIPTOR_H

#include <common.h>
#include <types.h>

#include <liberror.h>

#include "libexe_io_handle.h"
#include "libexe_libbfio.h"
#include "libexe_libfdata.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libexe_section_descriptor libexe_section_descriptor_t;

struct libexe_section_descriptor
{
	/* The name
	 */
	uint8_t name[ 9 ];

	/* The name size
	 */
	size_t name_size;

	/* The virtual address
	 */
	uint32_t virtual_adress;

	/* The data block
	 */
	libfdata_block_t *data_block;
};

int libexe_section_descriptor_initialize(
     libexe_section_descriptor_t **section_descriptor,
     liberror_error_t **error );

int libexe_section_descriptor_free(
     libexe_section_descriptor_t *section_descriptor,
     liberror_error_t **error );

int libexe_section_descriptor_clone(
     libexe_section_descriptor_t **destination_section_descriptor,
     libexe_section_descriptor_t *source_section_descriptor,
     liberror_error_t **error );

int libexe_section_descriptor_set_data_range(
     libexe_section_descriptor_t *section_descriptor,
     off64_t data_offset,
     size64_t data_size,
     liberror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
