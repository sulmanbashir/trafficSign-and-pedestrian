##
## Makefile for Rider companion in /Users/Fabien/Rider_Companion_Helmet
## 
## Made by Fabien Ries
## Login   <ries_f@epitech.net>
## 
## Started on  Wed Oct  4 23:13:41 2017 Fabien Ries
## Last update Wed Oct  4 23:17:03 2017 Fabien Ries
##

COMP	= g++

RM	= rm -f

NAME	= ridercompanion

SRCS	= main.cpp \
        Detection/Pieton/pieton_detection.cpp \
        Detection/Signal-panel/signal_panel.cpp \
        Detection/Signal-panel/find_triangles_panel.cpp \
        Detection/Signal-panel/find_circles_panel.cpp

CFLAGS = `pkg-config --cflags --libs opencv`

LIBS =  -lopencv_core -lopencv_videoio -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_stitching -lopencv_imgcodecs 

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(OBJS) $(CXXFLAGS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

