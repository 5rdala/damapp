#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cJSON.h>

#include "game.h"

static Damapp game = {};

void LoadGameData(GameData *dist)
{
	FILE *file = fopen(DATA_FILE_PATH, "r");
	if (!file) {
		fprintf(stderr, "Error: Failed to open %s for reading\n", DATA_FILE_PATH);
		return;
	}

	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	if (file_size <= 0) {
		fprintf(stderr, "Error: File size is invalid\n");
		fclose(file);
		return;
	}

	char *json_data = malloc(file_size + 1);
	if (!json_data) {
		fprintf(stderr, "Error: Failed to allocate memory for JSON data\n");
		fclose(file);
		return;
	}

	size_t read = fread(json_data, 1, file_size, file);
	if (read != (size_t)file_size) {
		fprintf(stderr, "Error: Failed to read entire file (read %zu bytes, expected %ld)\n", read,
				file_size);
		free(json_data);
		fclose(file);
		return;
	}
	json_data[file_size] = '\0';
	fclose(file);

	cJSON *root = cJSON_Parse(json_data);
	free(json_data);

	if (!root) {
		fprintf(stderr, "Error: Failed to parse JSON from %s\n", DATA_FILE_PATH);
		return;
	}

	cJSON *username = cJSON_GetObjectItemCaseSensitive(root, "username");
	cJSON *token = cJSON_GetObjectItemCaseSensitive(root, "token");

	if (cJSON_IsString(username) && cJSON_IsString(token)) {
		snprintf(dist->username, sizeof(dist->username), "%s", username->valuestring);
		snprintf(dist->token, sizeof(dist->token), "%s", token->valuestring);
	} else {
		fprintf(stderr, "Warning: JSON missing 'username' or 'token' fields\n");
	}

	cJSON_Delete(root);
}

void updateData(void)
{
	cJSON *root = cJSON_CreateObject();
	if (!root) {
		fprintf(stderr, "Error: Failed to create JSON object\n");
		return;
	}

	cJSON_AddStringToObject(root, "username", game.data.username);
	cJSON_AddStringToObject(root, "token", game.data.token);

	FILE *file = fopen(DATA_FILE_PATH, "w");
	if (!file) {
		fprintf(stderr, "Error: Failed to open %s for writing\n", DATA_FILE_PATH);
		cJSON_Delete(root);
		return;
	}

	char *json_data = cJSON_Print(root);
	if (json_data) {
		fprintf(file, "%s", json_data);
		free(json_data);
	} else {
		fprintf(stderr, "Error: Failed to serialize JSON\n");
	}
	fclose(file);
	cJSON_Delete(root);
}

Damapp *InitGame(void)
{
	game.state = MAIN_MENU;
	game.theme = THEME_WOOD;
	LoadGameData(&game.data);
	game.updateData = &updateData;
	return &game;
}

Damapp *GetGameStruct()
{
	return &game;
}
