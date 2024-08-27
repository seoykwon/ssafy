-- 데이터베이스 선택 또는 생성 (필요한 경우)
CREATE DATABASE IF NOT EXISTS todos;
USE todos;

-- todos 테이블 생성
CREATE TABLE todos (
    todo_id INT AUTO_INCREMENT PRIMARY KEY,  -- PK, 자동 증가
    title VARCHAR(255) NOT NULL,             -- 할 일 제목
    is_completed TINYINT(1) NOT NULL         -- 완료 여부 (1/0)
);

-- 더미 데이터 삽입
INSERT INTO todos (title, is_completed) VALUES
('밥먹기', 1),
('영화보기', 1),
('커피마시기', 0);

SELECT * FROM todos;

-- DROP DATABASE todo_database;