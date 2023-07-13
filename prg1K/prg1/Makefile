CC = gcc
CFLAGS = -Wall
INSTALL_DIR = /usr/local/bin

# サブディレクトリのリスト
SUBDIRS = 1 2 3 4 5 6 7 8 9 10 11 12 13

# サブディレクトリ内のソースコードを検索
SOURCES := $(shell find $(SUBDIRS) -name "*.c")

# ソースコードから実行ファイル名を生成
EXECUTABLES := $(patsubst %.c,%,$(SOURCES))

.PHONY: all install uninstall clean

all: $(EXECUTABLES)

# 実行ファイルのビルド
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

install: $(EXECUTABLES)
	@echo "Installing executables..."
	@mkdir -p $(INSTALL_DIR)
	@cp $(EXECUTABLES) $(INSTALL_DIR)

uninstall:
	@echo "Uninstalling executables..."
	@for executable in $(EXECUTABLES); do \
		rm -f $(INSTALL_DIR)/$$executable; \
	done

clean:
	@echo "Cleaning up..."
	@rm -f $(EXECUTABLES)
