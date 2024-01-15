<script setup lang="ts">
import { computed } from 'vue'
import { handleBackground } from '../layout-helper'

const props = defineProps({
    background: {
        type: String,
    },
    class: {
        type: String,
    },
})
</script>

<template>
    <div class="table w-full h-full">
        <div class="table-row">
            <div class="grid grid-cols-2 w-full h-full">
                <div class="slidev-layout default hu-red w-full h-full-40 big-title" :class="props.class">
                    <slot />
                </div>
                <div class="w-full h-full">
                    <img src="/slidev-theme-hu/assets/HUICTCover.jpg" style="object-fit: contain;" />
                </div>
            </div>
        </div>
        <div class="table-row hu-footer">
            <img class="logo" src="/slidev-theme-hu/assets/svg/hu-logo.svg">
            <h3 class="payoff hu-red-text">HIER&nbsp;KOMT<br />ALLES&nbsp;SAMEN</h3>
        </div>
    </div>
</template>
