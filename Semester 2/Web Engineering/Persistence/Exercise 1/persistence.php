<?php

$comment = $_POST["comment"];
save_comment($comment);
echo "Kommentar wurde gespeichert!";

function save_comment(string $comment): bool
{
    $current_comments = get_comments();
    $updated_comments = [$comment, ";", $current_comments];
    return file_put_contents("comments.txt", $updated_comments);
}

function get_comments(): string
{
    if (!is_readable("comments.txt")) {
        return "";
    }

    return file_get_contents("comments.txt");
}