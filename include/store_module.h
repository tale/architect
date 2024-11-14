#ifndef STORE_MODULE_H
#define STORE_MODULE_H

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include <sys/stat.h>

#define STORE_PATH "/opt/rootbeer/store"

// This struct is basically what an entire revision looks like
// in our store. As a basic explanation, we say that a revision
// contains some basic metadata, config data, and all of the
// "side effects" that are generated by the revision, such as
// IO related things like external files.
typedef struct {
	int id; // Revisions count up from 0
	char *name; // Name of the revision (optional)
	time_t timestamp; // Unix timestamp
	
	char **cfg_filesv; // Array of config file paths
	int cfg_filesc; // Number of config files
	
	char **ref_filesv; // Array of reference file paths
	int ref_filesc; // Number of reference files
} rb_revision_t;

rb_revision_t *rb_store_get_revision(const int id);
int rb_store_get_revision_count();

void rb_store_init_or_die();
void rb_store_destroy();

int rb_dump_revision(rb_revision_t *revision);

#endif // STORE_MODULE_H