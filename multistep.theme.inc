<?php
// $Id$

/**
 * Display a navigation block.
 * Use this theme function to override the output / display of this block.
 */
function theme_multistep_navigation($data = array()) {
  if(count($data) < 1) {
    return '';
  }
  foreach ($data as $key => $group) {
    extract($group);
    if (isset($url) || $next_unsubmitted_step) {
      $content[$key] = l($label, $url, array('attributes' => array('id' => $id, 'class' => $class), 'query' => array('step' => $step), 'fragment' => $anchor));
    }
    else {
      $content[$key] = '<span id="'. $id .'" class="' . implode(' ', $class) . '">' . $label . '</span>';
    }
  }
  return theme('item_list', array('items' => $content, 'type' => variable_get('multistep_show_step_numbers') ? 'ol' : 'ul'));
}

/**
 * Block Theme function that displays the default output of a progress bar.
 * Use this theme function to override the output / display of this block.
 */
function theme_multistep_progress_bar($progress) {
  $output = '<div class="multistep-progress-bar-wrapper">';
  $output .= '<div class="multistep-progress-bar multistep-progress-bar-' . $progress . '" style="width: ' . $progress . '%">' . $progress . '%</div>';
  $output .= '</div>';
  return $output;
}
