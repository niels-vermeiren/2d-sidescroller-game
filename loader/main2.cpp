
#include <iostream>
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

class Image {
public:
	Image(std::string n, SDL_Surface* sur) {
		name = n;
		surface = sur;
	}

	std::string getName() { return name; }
	SDL_Surface* getSurface() { return surface; }
private:
	std::string name;
	SDL_Surface* surface;
};

class Images{
public:
	Images(SDL_mutex* mu) {
		mutex = mu;
		completed = false;
	}

	std::vector<Image>* getImages() { return &images; }
	SDL_mutex* getMutex() { return mutex; }
	void setCompleted(bool comp) { completed = comp; }
	bool getCompleted() { return completed; }

private:
	SDL_mutex* mutex;
	bool completed;
	std::vector<Image> images;

};

static int LoadThread(void *ptr) {
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	Images *loading = (Images*)ptr;
	const int num = 200;
	std::string paths[num] = { 
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
		"img/1.png" , "img/1.png" , "img/1.png", "img/1.png", "img/1.png",
	};

	std::vector<Image> *images = loading->getImages();
	SDL_mutex *mutex = loading->getMutex();

	for (int i = 0; i < num; i++) {
		std::string name = "img" + std::to_string(i);
		SDL_Surface *sur = IMG_Load(paths[i].c_str());

		if (SDL_LockMutex(mutex) == 0) {
			std::cout << "Load image (SDL_Surface) : " << i << "\n";
			images->push_back(Image(name, sur));
			if (i == (num - 1))
				loading->setCompleted(true);
			SDL_UnlockMutex(mutex);
		} else {
			std::cout << "Couldn't lock the mutex for LoadThread\n";
		}
	}

	IMG_Quit();

	return 0;
}

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	TTF_Init();

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer);

	bool completed = false;
	bool confirm = false;

	SDL_mutex* mutex = SDL_CreateMutex();
	Images imgLoader (mutex);

	std::vector<Image>* images = imgLoader.getImages();

	std::vector<SDL_Texture*> imagesTex;

	TTF_Font *font = TTF_OpenFont("roboto.ttf", 30);

	SDL_Thread *thread = SDL_CreateThread(LoadThread, "Load", (void*) &imgLoader);

	size_t total = 0;

	while (!(completed && confirm)) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				confirm = true;
			}
		}

		size_t num = 0;

		if (SDL_LockMutex(mutex) == 0) {
			num = images->size();
			if (num > 0) {
				Image img = images->back();
				std::cout << "Create texture from image : " << img.getName() << "\n";
				SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, img.getSurface());
				imagesTex.push_back(tex);

				total++;
				SDL_FreeSurface(img.getSurface());
				images->pop_back();
			}
			completed = imgLoader.getCompleted();
			SDL_UnlockMutex(mutex);
		} else {
			std::cout << "Couldn't lock the mutex for MainThread\n";
		}
		
		
		std::string textLoading = "Loading " + std::to_string((total*100)/200) + " %";
		SDL_Surface *sur = TTF_RenderText_Blended(font, textLoading.c_str() , SDL_Color{ 255, 255, 255, 255 });
		int posX = (800 - sur->w) / 2;
		int posY = (600 - sur->h) / 2;
		SDL_Rect pos { posX, posY , sur->w, sur->h };
		SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, sur);
		SDL_FreeSurface(sur);

		SDL_Rect bgSrc{ 0, 0 , 4, 20 };
		SDL_Rect posBg{ 0, 340 , 4, 20 };

		SDL_RenderClear(renderer);

		for (size_t i = 0; i < imagesTex.size(); i++) {
			posBg.x = i*4;
			bgSrc.x = i;
			SDL_RenderCopy(renderer, imagesTex[i], &bgSrc, &posBg);
		}

		SDL_RenderCopy(renderer, tex, NULL, &pos);
		SDL_RenderPresent(renderer);

		SDL_DestroyTexture(tex);
	}

	for (auto img : imagesTex) {
		SDL_DestroyTexture(img);
	}

	SDL_DestroyMutex(mutex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}