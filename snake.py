import pygame
import random
import threading
from pygame.locals import *

# Funções auxiliares
def on_grid_random():
    x = random.randint(0, 59)
    y = random.randint(7, 59)  # Evitando que a area da pontuação passe de 74px
    return (x * 10, y * 10)

def collision(c1, c2):
    return (c1[0] == c2[0]) and (c1[1] == c2[1])

# Definindo as direção
DOWN = (0, 1)
UP = (0, -1)
LEFT = (-1, 0)
RIGHT = (1, 0)

# Função com thread pra movimentar a cobra e detectar a colisão dela
def snake_thread():
    global game_over, snake, direction, apple_pos, score, speed
    
    while not game_over:
        if not paused:
            if collision(snake[0], apple_pos):
                apple_pos = on_grid_random()
                snake.append((0, 0))
                score += 1
                speed = max(10, speed + 0.5)  # Acrescentando velocidade a cada ponto

            # Checando se a cobra colidiu com as bordas ou a área de pontuação
            if (snake[0][0] >= 600 or snake[0][1] >= 600 or 
                snake[0][0] < 0 or snake[0][1] < 60):
                game_over = True

            # Checando se a cobra colidiu com ela mesma
            for i in range(1, len(snake) - 1):
                if snake[0] == snake[i]:
                    game_over = True
                    break

            # Atualize a posição da cobra com base na direção atual
            new_head = (snake[0][0] + direction[0] * 10, snake[0][1] + direction[1] * 10)
            snake = [new_head] + snake[:-1]

        pygame.time.wait(50)  # Ajuste de velocidade da cobra

# Inicializando o pygame
pygame.init()
screen = pygame.display.set_mode((600, 600))
pygame.display.set_caption('Snake')

# Carregando a imagem de fundo
background_image = pygame.image.load('snake_back.png').convert()

# Inicializando a cobra e as maças 
snake = [(200, 200), (210, 200), (220, 200)]
snake_skin = pygame.Surface((10, 10))
snake_skin.fill((255, 255, 255))  # White

apple_pos = on_grid_random()
apple = pygame.Surface((10, 10))
apple.fill((255, 0, 0))

# Configuração inicial
direction = LEFT
game_over = False
score = 0  # Score inicial
speed = 10  # Velocidade inicial
paused = False

# Criando e dando start no thread da cobra
snake_thread = threading.Thread(target=snake_thread)
snake_thread.start()

# Loop principal do jogo
clock = pygame.time.Clock()
start_time = pygame.time.get_ticks()  # Dando start no tempo
while True:  # Loop principal para manter a janela aberta após o game_over
    clock.tick(60)  # Controle de FPS
    
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
        
        if event.type == KEYDOWN:
            if event.key == K_UP and direction != DOWN:
                direction = UP
            if event.key == K_DOWN and direction != UP:
                direction = DOWN
            if event.key == K_LEFT and direction != RIGHT:
                direction = LEFT
            if event.key == K_RIGHT and direction != LEFT:
                direction = RIGHT
            if event.key == K_p:
                paused = not paused
            if event.key == K_e and game_over:
                pygame.quit()
                exit()

    screen.blit(background_image, [0, 0])
    screen.blit(apple, apple_pos)
    
    # Mostrando o score na tela
    font = pygame.font.Font('freesansbold.ttf', 18)
    score_font = font.render('Score: %s' % (score), True, (255, 255, 255))
    score_rect = score_font.get_rect()
    score_rect.topleft = (10, 10)
    screen.blit(score_font, score_rect)

    # Exibindo o tempo do jogo
    elapsed_time = (pygame.time.get_ticks() - start_time) // 1000
    time_font = font.render('Time: %s' % (elapsed_time), True, (255, 255, 255))
    time_rect = time_font.get_rect()
    time_rect.topleft = (520, 10)
    screen.blit(time_font, time_rect)

    # Cobrinha
    for pos in snake:
        screen.blit(snake_skin, pos)
    
    # Tela de Game over 
    if game_over:
        end_font = pygame.font.Font('freesansbold.ttf', 36)
        end_text = end_font.render('GAME OVER', True, (255, 255, 255))
        end_rect = end_text.get_rect()
        end_rect.center = (300, 300)
        screen.blit(end_text, end_rect)

    # Tela de Pause
    if paused:
        pause_font = pygame.font.Font('freesansbold.ttf', 36)
        pause_text = pause_font.render('PAUSED', True, (255, 255, 255))
        pause_rect = pause_text.get_rect()
        pause_rect.center = (300, 300)
        screen.blit(pause_text, pause_rect)

    pygame.display.update()

snake_thread.join()  # Esperando os threads da cobra finalizarem
exit()
