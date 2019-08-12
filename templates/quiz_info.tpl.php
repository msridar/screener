<div class="jumbotron">
  <h1><?php print filter_xss($title); ?></h1>
  <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer pellentesque ante ligula, eget fringilla justo maximus quis. Quisque congue, nisi sed sollicitudin facilisis, orci diam fermentum lacus, vel tincidunt purus arcu vel sapien. Maecenas pharetra mauris accumsan enim dapibus, auctor laoreet nibh dictum. </p>
  <p><strong>Number of Questions: </strong><?php print $no_of_questions; ?></p>
  <p><a class="btn btn-primary btn-lg" href="/quiz/take/<?php print $test_nid; ?>" role="button">Start Test</a></p>
</div>
