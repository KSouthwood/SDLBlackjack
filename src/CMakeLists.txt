project(SDLBlackjack)

add_executable(blackjack main.cpp Controller.cpp Controller.h Renderer.cpp Renderer.h Renderer_Consts.h DeckOfCards.cpp DeckOfCards.h Card.cpp Card.h Helpers.cpp Helpers.h Textures.cpp Textures.h TextureMap.cpp TextureMap.h)
target_link_libraries(blackjack ${SDL2_LIBRARIES})